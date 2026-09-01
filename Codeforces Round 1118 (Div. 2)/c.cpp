#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    ll key;
    ll sum;
    ll lazy;

    int l, r;
    int sz;

    uint32_t pri;

    Node(ll _key = 0, uint32_t _pri = 0)
        : key(_key),
          sum(_key),
          lazy(0),
          l(0),
          r(0),
          sz(1),
          pri(_pri) {}
};

vector<Node> tr(1);

mt19937 rng(123456789);

int getSize(int x) {
    return x ? tr[x].sz : 0;
}

ll getSum(int x) {
    return x ? tr[x].sum : 0;
}

void addAll(int x, ll val) {
    if (!x) return;

    tr[x].key += val;
    tr[x].sum += val * tr[x].sz;
    tr[x].lazy += val;
}

void push(int x) {
    if (!x || tr[x].lazy == 0)
        return;

    ll val = tr[x].lazy;

    addAll(tr[x].l, val);
    addAll(tr[x].r, val);

    tr[x].lazy = 0;
}

void pull(int x) {
    tr[x].sz =
        1 +
        getSize(tr[x].l) +
        getSize(tr[x].r);

    tr[x].sum =
        tr[x].key +
        getSum(tr[x].l) +
        getSum(tr[x].r);
}

/*
    Split by key:

    a = keys < key
    b = keys >= key
*/
void splitKey(int t, ll key, int &a, int &b) {
    if (!t) {
        a = b = 0;
        return;
    }

    push(t);

    if (tr[t].key < key) {
        a = t;

        splitKey(
            tr[t].r,
            key,
            tr[t].r,
            b
        );

        pull(a);
    }
    else {
        b = t;

        splitKey(
            tr[t].l,
            key,
            a,
            tr[t].l
        );

        pull(b);
    }
}

/*
    Merge two treaps.

    All keys in a <= all keys in b.
*/
int mergeTreap(int a, int b) {
    if (!a) return b;
    if (!b) return a;

    if (tr[a].pri > tr[b].pri) {
        push(a);

        tr[a].r =
            mergeTreap(tr[a].r, b);

        pull(a);

        return a;
    }
    else {
        push(b);

        tr[b].l =
            mergeTreap(a, tr[b].l);

        pull(b);

        return b;
    }
}

/*
    Unite two treaps whose key ranges may overlap.
*/
int unite(int a, int b) {
    if (!a) return b;
    if (!b) return a;

    if (tr[a].pri < tr[b].pri)
        swap(a, b);

    push(a);
    push(b);

    int leftPart, rightPart;

    splitKey(
        b,
        tr[a].key,
        leftPart,
        rightPart
    );

    tr[a].l =
        unite(tr[a].l, leftPart);

    tr[a].r =
        unite(tr[a].r, rightPart);

    pull(a);

    return a;
}

/*
    Split by number of elements.

    First k elements -> a
    Rest            -> b
*/
void splitCount(int t, int k, int &a, int &b) {
    if (!t) {
        a = b = 0;
        return;
    }

    push(t);

    int leftSize = getSize(tr[t].l);

    if (k <= leftSize) {
        b = t;

        splitCount(
            tr[t].l,
            k,
            a,
            tr[t].l
        );

        pull(b);
    }
    else {
        a = t;

        splitCount(
            tr[t].r,
            k - leftSize - 1,
            tr[t].r,
            b
        );

        pull(a);
    }
}

int newNode(ll value) {
    tr.emplace_back(
        value,
        rng()
    );

    return (int)tr.size() - 1;
}

/*
    Sum of all negative slopes.
*/
ll sumNegative(int &root) {
    int negative, nonNegative;

    splitKey(
        root,
        0,
        negative,
        nonNegative
    );

    ll ans = getSum(negative);

    root = mergeTreap(
        negative,
        nonNegative
    );

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        vector<int> a(n);

        for (int &x : a)
            cin >> x;

        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;

            --u;
            --v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Root the tree at 0.
        vector<int> parent(n, -1);
        vector<int> order;

        order.reserve(n);
        order.push_back(0);

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];

            for (int v : adj[u]) {
                if (v == parent[u])
                    continue;

                parent[v] = u;
                order.push_back(v);
            }
        }

        /*
            For every subtree v:

            L[v] = number of fixed +1 nodes.

            Z[v] = number of zero nodes.

            Therefore possible number of +1 nodes is:

                L[v] ... L[v] + Z[v]

            base[v] = F_v(L[v])

            root[v] = treap containing
                      the slopes of F_v.
        */

        vector<int> root(n, 0);

        vector<int> L(n, 0);
        vector<int> Z(n, 0);
        vector<int> subtreeSize(n, 0);

        vector<ll> base(n, 0);

        // Bottom-up DP
        for (int idx = n - 1; idx >= 0; idx--) {

            int u = order[idx];

            int rt = 0;

            int fixedPlus = 0;
            int zeros = 0;

            int sz = 1;

            ll curBase = 0;

            /*
                Combine all children.

                Infimal convolution of convex functions
                corresponds to merging their slope sequences.
            */
            for (int v : adj[u]) {

                if (parent[v] != u)
                    continue;

                fixedPlus += L[v];
                zeros += Z[v];
                sz += subtreeSize[v];

                curBase += base[v];

                rt = unite(
                    rt,
                    root[v]
                );
            }

            /*
                Determine the minimum possible number
                of +1 nodes in this subtree.
            */
            int low;

            if (a[u] == 1) {
                // Current node must be +1.
                low = fixedPlus + 1;
            }
            else {
                // -1 or zero.
                low = fixedPlus;
            }

            /*
                If a[u] == 0:

                We may choose it as -1 or +1.

                In terms of F(k), this is:

                    min(C(k), C(k-1))

                For a convex function this simply
                inserts one zero slope.
            */
            if (a[u] == 0) {

                int node = newNode(0);

                rt = unite(rt, node);

                zeros++;
            }

            /*
                Cost of vertex u:

                    |subtree sum|

                If there are k pluses in a subtree
                of size sz:

                    pluses = k
                    minuses = sz-k

                    sum = k-(sz-k)
                        = 2k-sz

                Therefore:

                    cost = |2k-sz|
            */

            curBase += llabs(
                2LL * low - sz
            );

            int high = low + zeros;

            /*
                Slopes of:

                    |2k-sz|

                are:

                    -2 ... -2
                    optional 0
                    +2 ... +2

                We need to add these slopes
                element-by-element to the existing
                DP slopes.
            */

            // Number of -2 slopes.
            int negativeCount =
                max(
                    0,
                    min(
                        zeros,
                        sz / 2 - low
                    )
                );

            /*
                Positive slopes happen for:

                    k > ceil(sz/2)
            */
            int positiveStart =
                max(
                    low,
                    (sz + 1) / 2
                );

            int positiveCount =
                max(
                    0,
                    high - positiveStart
                );

            /*
                Add -2 to the first negativeCount slopes.
            */
            if (negativeCount > 0) {

                int x, y;

                splitCount(
                    rt,
                    negativeCount,
                    x,
                    y
                );

                addAll(x, -2);

                rt = mergeTreap(x, y);
            }

            /*
                Add +2 to the last positiveCount slopes.
            */
            if (positiveCount > 0) {

                int x, y;

                splitCount(
                    rt,
                    zeros - positiveCount,
                    x,
                    y
                );

                addAll(y, 2);

                rt = mergeTreap(x, y);
            }

            L[u] = low;
            Z[u] = zeros;
            subtreeSize[u] = sz;

            base[u] = curBase;
            root[u] = rt;
        }

        /*
            F_root(k) is convex.

            Therefore its minimum is reached after
            all negative slopes have been taken.

            So:

                answer =
                    base
                    + sum(all negative slopes)
        */
        ll answer =
            base[0] +
            sumNegative(root[0]);

        cout << answer << '\n';
    }

    return 0;
}