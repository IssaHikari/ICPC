#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> parent(n + 1, 0);
    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }

    int m;
    cin >> m;
    vector<int> is_target(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        is_target[a] = 1;
    }

    // Stores the count of target nodes in the subtree of u
    vector<int> target_count(n + 1, 0);

    // Bottom-up computation (using 1..n order since parent[i] < i)
    for (int i = n; i >= 1; --i) {
        target_count[i] += is_target[i];
        if (i > 1) {
            target_count[parent[i]] += target_count[i];
        }
    }

    vector<int> cameras;
    // Collect nodes u where placing a camera on edge (u, parent[u]) is needed
    for (int i = 2; i <= n; ++i) {
        if (target_count[i] >= 1 && target_count[i] < m) {
            cameras.push_back(i);
        }
    }

    // Output answer
    cout << cameras.size();
    for (int u : cameras) {
        cout << " " << u;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}