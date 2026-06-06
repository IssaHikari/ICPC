#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> color;

tuple<ll, ll, bool> bfs(int start) {
    queue<int> q;
    q.push(start);

    color[start] = 0;

    ll cnt[2] = {1, 0};
    bool bipartite = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                cnt[color[v]]++;
                q.push(v);
            }
            else if (color[v] == color[u]) {
                bipartite = false;
            }
        }
    }

    return {cnt[0], cnt[1], bipartite};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    color.assign(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll answer = 0;

    for (int i = 1; i <= N; i++) {
        if (color[i] == -1) {
            auto [cnt0, cnt1, bipartite] = bfs(i);

            if (bipartite) {
                answer += 2026LL * max(cnt0, cnt1);
            } else {
                answer += 1013LL * (cnt0 + cnt1);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}