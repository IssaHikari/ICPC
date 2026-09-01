#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int ans = 0;

void dfs(int u, int depth) {
    ans = max(ans, depth);

    for (int v : adj[u])
        dfs(v, depth + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    adj.resize(n + 1);
    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];

        if (v[i] != -1)
            adj[v[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] == -1)
            dfs(i, 1);
    }

    cout << ans << endl;

    return 0;
}
