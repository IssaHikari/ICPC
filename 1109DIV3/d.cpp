#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct SubtreeInfo {
    int L, R, sz;
    bool valid;
};

int k;
vector<vector<int>> adj;
vector<int> a;
vector<SubtreeInfo> res;

void dfs(int u) {
    // Base Case: If the node is a leaf
    if (adj[u].empty()) {
        res[u] = {a[u] - 1, a[u] - 1, 1, true};
        return;
    }

    int total_sz = 0;
    bool children_valid = true;

    // Post-order traversal: Process all children first
    for (int v : adj[u]) {
        dfs(v);
        total_sz += res[v].sz;
        if (!res[v].valid) {
            children_valid = false;
        }
    }

    if (!children_valid) {
        res[u] = {0, 0, total_sz, false};
        return;
    }

    int m = adj[u].size();
    int mismatches = 0;
    int mismatch_idx = -1;

    // Count transitions where continuity breaks circularly
    for (int j = 0; j < m; ++j) {
        int curr = adj[u][j];
        int nxt = adj[u][(j + 1) % m];
        if ((res[curr].R + 1) % k != res[nxt].L) {
            mismatches++;
            mismatch_idx = j;
        }
    }

    // Validate based on whether the subtree covers all leaves or a part of them
    if (total_sz < k) {
        if (mismatches != 1) {
            res[u] = {0, 0, total_sz, false};
        } else {
            int start_child = adj[u][(mismatch_idx + 1) % m];
            int end_child = adj[u][mismatch_idx];
            res[u] = {res[start_child].L, res[end_child].R, total_sz, true};
        }
    } else { // total_sz == k
        if (mismatches != 0) {
            res[u] = {0, 0, total_sz, false};
        } else {
            res[u] = {0, k - 1, total_sz, true};
        }
    }
}

void solve() {
    int n;
    cin >> n;

    adj.assign(n + 1, vector<int>());
    a.resize(n + 1);
    res.resize(n + 1);
    k = 0;

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i); // Naturally sorted by index
    }

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > 0) {
            k++;
        }
    }

    dfs(1);

    if (res[1].valid) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}