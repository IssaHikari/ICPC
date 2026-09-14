#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> adj;
vector<ll> tin, tout, value;
ll timer = 0;

void dfs(ll u, ll parent) {
    tin[u] = timer++;

    for (ll v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
    }

    tout[u] = timer - 1;
}

struct SegmentTree {
    ll n;
    vector<ll> tree;

    SegmentTree(vector<ll>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(ll node, ll l, ll r, vector<ll>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        ll mid = (l + r) / 2;

        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(ll node, ll l, ll r, ll pos, ll val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        ll mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, r, pos, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(ll pos, ll val) {
        update(1, 0, n - 1, pos, val);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        ll mid = (l + r) / 2;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    ll query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    adj.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    value.resize(n + 1);

    for (ll i = 1; i <= n; i++) {
        ll p;
        cin >> p;

        if (p != 0) {
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
    }

    for (ll i = 1; i <= n; i++) {
        cin >> value[i];
    }

    dfs(1, 0);

    vector<ll> euler(n);

    for (ll u = 1; u <= n; u++) {
        euler[tin[u]] = value[u];
    }

    SegmentTree seg(euler);

    ll q;
    cin >> q;

    while (q--) {
        ll type;
        cin >> type;

        if (type == 1) {
            ll u, x;
            cin >> u >> x;

            value[u] = x;
            seg.update(tin[u], x);
        }
        else {
            ll u;
            cin >> u;

            cout << seg.query(tin[u], tout[u]) << '\n';
        }
    }

    return 0;
}