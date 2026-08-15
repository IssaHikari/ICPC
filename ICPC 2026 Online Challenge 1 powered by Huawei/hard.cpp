#include <bits/stdc++.h>
using namespace std;

// ============================================================
// States (kept mainly for clarity / debugging; queues are the
// real source of truth for what is schedulable right now)
// ============================================================

enum State {
    ARRIVED,
    WAIT_P_PROC,
    WAIT_P_POST,
    READY_DECODE,
    WAIT_D_PROC,
    WAIT_D_POST,
    FINISHED
};

struct Request {
    int id = -1;
    int Lin = 0;
    int remote = -1;      // fixed at P PRE time
    State state = ARRIVED;
    bool finished = false;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ========================================================
    // 1. Startup configuration
    // ========================================================

    int K;
    double S, latency_in_ms, bandwidth_gbps;
    long long bytes_per_token;
    int num_layers;

    cin >> K >> S >> latency_in_ms >> bandwidth_gbps >> bytes_per_token >> num_layers;

    double SLO1, SLO2, tp_UB, tp_base, dist_base, w_tp, w_c;
    cin >> SLO1 >> SLO2 >> tp_UB >> tp_base >> dist_base >> w_tp >> w_c;

    // ========================================================
    // 2. Task-time table (read fully; not needed for the greedy
    //    batching strategy below, but must be consumed).
    // ========================================================

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int batch_size;
        double prefill_pre, prefill_proc, prefill_post;
        double decode_pre, decode_proc, decode_post;

        cin >> batch_size
            >> prefill_pre >> prefill_proc >> prefill_post
            >> decode_pre  >> decode_proc  >> decode_post;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // ========================================================
    // 3. Resources
    // ========================================================

    const int MAXR = 2005;

    vector<Request> requests(MAXR);
    vector<bool> exists(MAXR, false);

    bool edge_free = true;
    vector<bool> cloud_free(K, true);

    // ========================================================
    // 4. Scheduling queues — these ARE the batching mechanism.
    //    Every request that becomes eligible for a step is
    //    pushed here; when the corresponding resource is free
    //    we drain the WHOLE queue into one grouped task.
    // ========================================================

    queue<int> arrivalQueue;                 // -> P PRE               (edge)
    vector<queue<int>> readyPProc(K);        // -> P PROC per remote   (cloud)
    queue<int> readyPPost;                   // -> P POST              (edge)

    queue<int> readyDecode;                  // -> D PRE (can span remotes) (edge)
    vector<queue<int>> readyDProc(K);        // -> D PROC per remote   (cloud)
    queue<int> readyDPost;                   // -> D POST (can span remotes) (edge)

    // Requests that just completed D POST this frame; we defer
    // deciding whether to re-queue them for another D PRE until
    // the WHOLE frame (including any FIN on the same rid) has
    // been read, since FIN can appear after the D POST TDN line
    // in the very same frame.
    vector<int> pendingAfterPost;

    int next_remote = 0;

    // ========================================================
    // 5. Interaction loop
    // ========================================================

    while (true) {

        string line;
        if (!getline(cin, line)) return 0;
        if (line == "END") return 0;

        // timestamp (unused directly; interactor drives all timing)
        (void)stod(line);

        if (!getline(cin, line)) return 0;
        int event_count = stoi(line);

        pendingAfterPost.clear();

        for (int e = 0; e < event_count; e++) {

            string type;
            cin >> type;

            // =========================================
            // ARR
            // =========================================
            if (type == "ARR") {
                int rid, Lin;
                cin >> rid >> Lin;

                Request r;
                r.id = rid;
                r.Lin = Lin;
                r.remote = -1;
                r.state = ARRIVED;
                r.finished = false;

                requests[rid] = r;
                exists[rid] = true;

                arrivalQueue.push(rid);
            }

            // =========================================
            // TDN
            // =========================================
            else if (type == "TDN") {

                string server, stage;
                cin >> server >> stage;

                if (stage == "P") {

                    string step;
                    cin >> step;

                    if (step == "PRE") {
                        int remote, rid; double dur;
                        cin >> remote >> rid >> dur;

                        edge_free = true;
                        requests[rid].state = WAIT_P_PROC;
                        // waits for XDN UP PRE to enter readyPProc[remote]
                    }
                    else if (step == "PROC") {
                        int ls, le, remote, rid; double dur;
                        cin >> ls >> le >> remote >> rid >> dur;

                        cloud_free[remote] = true;
                        // we always submit one full [0, num_layers) piece,
                        // so this is always the last piece -> XDN DOWN queued
                        requests[rid].state = WAIT_P_POST;
                    }
                    else if (step == "POST") {
                        int remote, rid; double dur;
                        cin >> remote >> rid >> dur;

                        edge_free = true;
                        requests[rid].state = READY_DECODE;
                        readyDecode.push(rid);
                    }
                }
                else if (stage == "D") {

                    string step;
                    cin >> step;

                    if (step == "PRE") {
                        int marker, m;
                        cin >> marker >> m;

                        vector<int> ids(m);
                        for (int i = 0; i < m; i++) cin >> ids[i];

                        double dur;
                        cin >> dur;

                        edge_free = true;
                        for (int rid : ids) requests[rid].state = WAIT_D_PROC;
                        // waits for per-remote XDN UP DEC to enter readyDProc[remote]
                    }
                    else if (step == "PROC") {
                        int remote, m;
                        cin >> remote >> m;

                        vector<int> ids(m);
                        for (int i = 0; i < m; i++) cin >> ids[i];

                        double dur;
                        cin >> dur;

                        cloud_free[remote] = true;
                        for (int rid : ids) requests[rid].state = WAIT_D_POST;
                        // waits for XDN DOWN DEC to enter readyDPost
                    }
                    else if (step == "POST") {
                        int marker, m;
                        cin >> marker >> m;

                        vector<int> ids(m);
                        for (int i = 0; i < m; i++) cin >> ids[i];

                        double dur;
                        cin >> dur;

                        edge_free = true;

                        // Do NOT decide re-queueing yet: FIN for any of
                        // these ids may still appear later in this frame.
                        for (int rid : ids) pendingAfterPost.push_back(rid);
                    }
                }
            }

            // =========================================
            // XDN
            // =========================================
            else if (type == "XDN") {

                string direction;
                int remote;
                long long size;
                string ttype;
                int m;

                cin >> direction >> remote >> size >> ttype >> m;

                vector<int> ids(m);
                for (int i = 0; i < m; i++) cin >> ids[i];

                if (ttype == "PRE") {
                    if (direction == "UP") {
                        for (int rid : ids) {
                            int rem = requests[rid].remote;
                            readyPProc[rem].push(rid);
                        }
                    } else { // DOWN
                        for (int rid : ids) readyPPost.push(rid);
                    }
                } else { // DEC
                    if (direction == "UP") {
                        for (int rid : ids) {
                            int rem = requests[rid].remote;
                            readyDProc[rem].push(rid);
                        }
                    } else { // DOWN
                        for (int rid : ids) readyDPost.push(rid);
                    }
                }
            }

            // =========================================
            // FIN
            // =========================================
            else if (type == "FIN") {
                int rid;
                cin >> rid;

                requests[rid].finished = true;
                requests[rid].state = FINISHED;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Now that the whole frame (including any FIN) has been
        // read, flush the deferred D POST completions: anything
        // not finished goes back into the decode-ready queue for
        // its next iteration.
        for (int rid : pendingAfterPost) {
            if (!requests[rid].finished) {
                requests[rid].state = READY_DECODE;
                readyDecode.push(rid);
            }
        }

        // ========================================================
        // Scheduling — greedy full batching + fixed priority order
        //   Edge:   D POST > D PRE > P POST > P PRE
        //   Remote: D PROC > P PROC
        // ========================================================

        vector<string> assignments;

        // ---------------- Edge: D POST ----------------
        if (edge_free && !readyDPost.empty()) {
            vector<int> ids;
            while (!readyDPost.empty()) {
                ids.push_back(readyDPost.front());
                readyDPost.pop();
            }
            string cmd = "E D POST -1 " + to_string(ids.size());
            for (int id : ids) cmd += " " + to_string(id);
            assignments.push_back(cmd);
            edge_free = false;
        }

        // ---------------- Edge: D PRE ----------------
        if (edge_free && !readyDecode.empty()) {
            vector<int> ids;
            while (!readyDecode.empty()) {
                ids.push_back(readyDecode.front());
                readyDecode.pop();
            }
            string cmd = "E D PRE -1 " + to_string(ids.size());
            for (int id : ids) cmd += " " + to_string(id);
            assignments.push_back(cmd);
            edge_free = false;
            for (int id : ids) requests[id].state = WAIT_D_PROC;
        }

        // ---------------- Edge: P POST ----------------
        if (edge_free && !readyPPost.empty()) {
            int rid = readyPPost.front();
            readyPPost.pop();
            assignments.push_back("E P POST " + to_string(requests[rid].remote) + " " + to_string(rid));
            edge_free = false;
        }

        // ---------------- Edge: P PRE ----------------
        if (edge_free && !arrivalQueue.empty()) {
            int rid = arrivalQueue.front();
            arrivalQueue.pop();

            int remote = next_remote;
            next_remote = (next_remote + 1) % K;

            requests[rid].remote = remote;
            requests[rid].state = WAIT_P_PROC;

            assignments.push_back("E P PRE " + to_string(remote) + " " + to_string(rid));
            edge_free = false;
        }

        // ---------------- Remotes: D PROC then P PROC ----------------
        for (int remote = 0; remote < K; remote++) {
            if (!cloud_free[remote]) continue;

            if (!readyDProc[remote].empty()) {
                vector<int> ids;
                while (!readyDProc[remote].empty()) {
                    ids.push_back(readyDProc[remote].front());
                    readyDProc[remote].pop();
                }
                string cmd = "C" + to_string(remote) + " D PROC " + to_string(remote) + " " + to_string(ids.size());
                for (int id : ids) cmd += " " + to_string(id);
                assignments.push_back(cmd);
                cloud_free[remote] = false;
            }
            else if (!readyPProc[remote].empty()) {
                int rid = readyPProc[remote].front();
                readyPProc[remote].pop();

                assignments.push_back(
                    "C" + to_string(remote) + " P PROC 0 " + to_string(num_layers) +
                    " " + to_string(remote) + " " + to_string(rid)
                );
                cloud_free[remote] = false;
            }
        }

        // ========================================================
        // Emit response
        // ========================================================

        cout << assignments.size() << '\n';
        for (const string &cmd : assignments) cout << cmd << '\n';
        cout.flush();
    }

    return 0;
}