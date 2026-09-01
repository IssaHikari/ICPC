#include <bits/stdc++.h>
using namespace std;

const int MAXR = 2005;

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
    int remote = -1;
    State state = ARRIVED;
    bool finished = false;
    bool in_flight = false;
};

class Scheduler {
private:
    int K;
    double S, latency, bandwidth;
    long long bytes_per_token;
    int num_layers;
    
    double SLO1, SLO2, tp_UB, tp_base, dist_base, w_tp, w_c;
    
    vector<Request> requests;
    vector<bool> exists;
    
    bool edge_free = true;
    vector<bool> cloud_free;
    
    queue<int> arrivalQueue;
    vector<queue<int>> readyPProc;
    queue<int> readyPPost;
    queue<int> readyDecode;
    vector<queue<int>> readyDProc;
    queue<int> readyDPost;
    
    int next_remote = 0;
    vector<int> pendingAfterPost;
    
public:
    Scheduler() {
        cloud_free.assign(8, true);
    }
    
    void read_config() {
        cin >> K >> S >> latency >> bandwidth >> bytes_per_token >> num_layers;
        cin >> SLO1 >> SLO2 >> tp_UB >> tp_base >> dist_base >> w_tp >> w_c;
        
        cloud_free.assign(K, true);
        readyPProc.resize(K);
        readyDProc.resize(K);
        
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int batch_size;
            double prefill_pre, prefill_proc, prefill_post;
            double decode_pre, decode_proc, decode_post;
            cin >> batch_size >> prefill_pre >> prefill_proc >> prefill_post
                >> decode_pre >> decode_proc >> decode_post;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        requests.resize(MAXR);
        exists.assign(MAXR, false);
    }
    
    void process_frame() {
        string line;
        if (!getline(cin, line)) exit(0);
        if (line == "END") exit(0);
        
        double timestamp = stod(line);
        
        if (!getline(cin, line)) exit(0);
        int event_count = stoi(line);
        
        pendingAfterPost.clear();
        
        for (int e = 0; e < event_count; e++) {
            string type;
            cin >> type;
            
            if (type == "ARR") {
                int rid, Lin;
                cin >> rid >> Lin;
                
                requests[rid].id = rid;
                requests[rid].Lin = Lin;
                requests[rid].state = ARRIVED;
                requests[rid].finished = false;
                requests[rid].in_flight = false;
                exists[rid] = true;
                
                arrivalQueue.push(rid);
            }
            else if (type == "TDN") {
                string server, stage;
                cin >> server >> stage;
                
                if (stage == "P") {
                    string step;
                    cin >> step;
                    
                    if (step == "PRE") {
                        int remote, rid;
                        double dur;
                        cin >> remote >> rid >> dur;
                        edge_free = true;
                        requests[rid].in_flight = false;
                    }
                    else if (step == "PROC") {
                        int ls, le, remote, rid;
                        double dur;
                        cin >> ls >> le >> remote >> rid >> dur;
                        cloud_free[remote] = true;
                        requests[rid].in_flight = false;
                    }
                    else if (step == "POST") {
                        int remote, rid;
                        double dur;
                        cin >> remote >> rid >> dur;
                        edge_free = true;
                        requests[rid].state = READY_DECODE;
                        requests[rid].in_flight = false;
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
                        for (int rid : ids) {
                            requests[rid].in_flight = false;
                            requests[rid].state = WAIT_D_PROC;
                        }
                    }
                    else if (step == "PROC") {
                        int remote, m;
                        cin >> remote >> m;
                        vector<int> ids(m);
                        for (int i = 0; i < m; i++) cin >> ids[i];
                        double dur;
                        cin >> dur;
                        
                        cloud_free[remote] = true;
                        for (int rid : ids) {
                            requests[rid].in_flight = false;
                            requests[rid].state = WAIT_D_POST;
                        }
                    }
                    else if (step == "POST") {
                        int marker, m;
                        cin >> marker >> m;
                        vector<int> ids(m);
                        for (int i = 0; i < m; i++) cin >> ids[i];
                        double dur;
                        cin >> dur;
                        
                        edge_free = true;
                        for (int rid : ids) {
                            requests[rid].in_flight = false;
                        }
                        pendingAfterPost.insert(pendingAfterPost.end(), ids.begin(), ids.end());
                    }
                }
            }
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
                            readyPProc[remote].push(rid);
                        }
                    } else {
                        for (int rid : ids) {
                            readyPPost.push(rid);
                        }
                    }
                } else {
                    if (direction == "UP") {
                        for (int rid : ids) {
                            readyDProc[remote].push(rid);
                        }
                    } else {
                        for (int rid : ids) {
                            readyDPost.push(rid);
                        }
                    }
                }
            }
            else if (type == "FIN") {
                int rid;
                cin >> rid;
                requests[rid].finished = true;
                requests[rid].state = FINISHED;
            }
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        for (int rid : pendingAfterPost) {
            if (!requests[rid].finished) {
                requests[rid].state = READY_DECODE;
                readyDecode.push(rid);
            }
        }
        
        vector<string> assignments = make_scheduling_decisions();
        
        cout << assignments.size() << '\n';
        for (const string& cmd : assignments) {
            cout << cmd << '\n';
        }
        cout.flush();
    }
    
private:
    vector<string> make_scheduling_decisions() {
        vector<string> assignments;
        
        // ============================================================
        // الحاسوب المحلي - تماماً مثل الكود الأصلي
        // ============================================================
        
        // 1. D POST
        if (edge_free && !readyDPost.empty()) {
            vector<int> batch;
            while (!readyDPost.empty()) {
                int rid = readyDPost.front();
                readyDPost.pop();
                if (!requests[rid].finished && !requests[rid].in_flight) {
                    batch.push_back(rid);
                }
            }
            if (!batch.empty()) {
                string cmd = "E D POST -1 " + to_string(batch.size());
                for (int id : batch) cmd += " " + to_string(id);
                assignments.push_back(cmd);
                edge_free = false;
                for (int id : batch) requests[id].in_flight = true;
            }
        }
        
        // 2. D PRE
        if (edge_free && !readyDecode.empty()) {
            vector<int> batch;
            while (!readyDecode.empty()) {
                int rid = readyDecode.front();
                readyDecode.pop();
                if (!requests[rid].finished && !requests[rid].in_flight) {
                    batch.push_back(rid);
                }
            }
            if (!batch.empty()) {
                string cmd = "E D PRE -1 " + to_string(batch.size());
                for (int id : batch) cmd += " " + to_string(id);
                assignments.push_back(cmd);
                edge_free = false;
                for (int id : batch) {
                    requests[id].state = WAIT_D_PROC;
                    requests[id].in_flight = true;
                }
            }
        }
        
        // 3. P POST
        if (edge_free && !readyPPost.empty()) {
            int rid = readyPPost.front();
            readyPPost.pop();
            if (!requests[rid].finished && !requests[rid].in_flight) {
                assignments.push_back("E P POST " + to_string(requests[rid].remote) + " " + to_string(rid));
                edge_free = false;
                requests[rid].in_flight = true;
            } else {
                readyPPost.push(rid);
            }
        }
        
        // 4. P PRE
        if (edge_free && !arrivalQueue.empty()) {
            int rid = arrivalQueue.front();
            arrivalQueue.pop();
            if (!requests[rid].finished && !requests[rid].in_flight) {
                int remote = next_remote % K;
                next_remote = (next_remote + 1) % K;
                requests[rid].remote = remote;
                requests[rid].state = WAIT_P_PROC;
                
                assignments.push_back("E P PRE " + to_string(remote) + " " + to_string(rid));
                edge_free = false;
                requests[rid].in_flight = true;
            } else {
                arrivalQueue.push(rid);
            }
        }
        
        // ============================================================
        // الحواسيب البعيدة
        // ============================================================
        for (int remote = 0; remote < K; remote++) {
            if (!cloud_free[remote]) continue;
            
            // D PROC
            if (!readyDProc[remote].empty()) {
                vector<int> batch;
                while (!readyDProc[remote].empty()) {
                    int rid = readyDProc[remote].front();
                    readyDProc[remote].pop();
                    if (!requests[rid].finished && !requests[rid].in_flight) {
                        batch.push_back(rid);
                    }
                }
                if (!batch.empty()) {
                    string cmd = "C" + to_string(remote) + " D PROC " + to_string(remote) + " " + 
                                to_string(batch.size());
                    for (int id : batch) cmd += " " + to_string(id);
                    assignments.push_back(cmd);
                    cloud_free[remote] = false;
                    for (int id : batch) requests[id].in_flight = true;
                }
            }
            // P PROC - قطعة واحدة كاملة
            else if (!readyPProc[remote].empty()) {
                int rid = readyPProc[remote].front();
                readyPProc[remote].pop();
                
                if (!requests[rid].finished && !requests[rid].in_flight) {
                    assignments.push_back("C" + to_string(remote) + " P PROC 0 " + 
                                        to_string(num_layers) + " " +
                                        to_string(remote) + " " + to_string(rid));
                    cloud_free[remote] = false;
                    requests[rid].in_flight = true;
                } else {
                    readyPProc[remote].push(rid);
                }
            }
        }
        
        return assignments;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Scheduler scheduler;
    scheduler.read_config();
    
    while (true) {
        scheduler.process_frame();
    }
    
    return 0;
}