#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<ll> a(n + 1);
        vector<ll> b(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i <= n; i++)
            cin >> b[i];

        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n + 1, 0);
        vector<int> order;
        order.reserve(n);

        order.push_back(1);

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];

            for (int v : adj[u]) {
                if (v == parent[u])
                    continue;

                parent[v] = u;
                order.push_back(v);
            }
        }

        vector<ll> step(n + 1);

        vector<ll> mx(n + 1);

        ll answer = 0;

        // Bottom-up
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            ll sumA = 0;
            ll g = b[u];

            for (int v : adj[u]) {
                if (parent[v] != u)
                    continue;

                sumA += a[v];

                g = gcd(g, step[v]);
            }

            g = gcd(g, sumA);

            mx[u] = b[u] - g + (a[u] % g);

            step[u] = (g == b[u] ? 0 : g);

            answer += mx[u];
        }

        cout << answer << '\n';
    }

    return 0;
}