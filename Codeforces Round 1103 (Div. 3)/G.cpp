#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int LOG = 20;

vector<int> adj[N];
int up[N][LOG], depth[N];
int parent[N];

int n, q;
int a[N];

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i < LOG; i++) {
        if (up[v][i - 1] != -1)
            up[v][i] = up[up[v][i - 1]][i - 1];
        else
            up[v][i] = -1;
    }

    for (int u : adj[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];

    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i))
            a = up[a][i];

    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}


vector<int> getPath(int u, int v) {
    int w = lca(u, v);

    vector<int> path1, path2;

    while (u != w) {
        path1.push_back(a[u]);
        u = up[u][0];
    }

    path1.push_back(a[w]);

    while (v != w) {
        path2.push_back(a[v]);
        v = up[v][0];
    }

    reverse(path2.begin(), path2.end());

    for (auto x : path2)
        path1.push_back(x);

    return path1;
}

long long solveArray(vector<int> &v) {
    long long ans = 0;
    int l = 0;
    int mask = 0;

    for (int r = 0; r < v.size(); r++) {
        while ((mask & v[r]) != 0) {
            mask ^= v[l];
            l++;
        }

        mask |= v[r];
        ans += (r - l + 1);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(up, -1, sizeof(up));
    depth[1] = 0;
    dfs(1, -1);

    while (q--) {
        int x, y;
        cin >> x >> y;

        vector<int> path = getPath(x, y);

        cout << solveArray(path) << "\n";
    }
}