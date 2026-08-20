#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct SegTree {
    int n;
    vector<int> mn, mx, lazy;

    SegTree(int n) : n(n) {
        mn.resize(4 * n);
        mx.resize(4 * n);
        lazy.resize(4 * n);

        build(1, 0, n - 1);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            // Initially:
            // number of smaller elements = 0
            // so f[x] = 0 - x
            mn[node] = mx[node] = -l;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        pull(node);
    }

    void pull(int node) {
        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
    }

    void apply(int node, int value) {
        mn[node] += value;
        mx[node] += value;
        lazy[node] += value;
    }

    void push(int node) {
        if (lazy[node] != 0) {
            apply(node * 2, lazy[node]);
            apply(node * 2 + 1, lazy[node]);
            lazy[node] = 0;
        }
    }

    void add(int ql, int qr, int value) {
        if (ql > qr)
            return;

        add(1, 0, n - 1, ql, qr, value);
    }

    void add(int node, int l, int r,
             int ql, int qr, int value) {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(node, value);
            return;
        }

        push(node);

        int mid = (l + r) / 2;

        add(node * 2, l, mid, ql, qr, value);
        add(node * 2 + 1, mid + 1, r, ql, qr, value);

        pull(node);
    }

    // Remove this value from possible candidates.
    void remove(int pos) {
        remove(1, 0, n - 1, pos);
    }

    void remove(int node, int l, int r, int pos) {
        if (l == r) {
            mn[node] = mx[node] = INF;
            lazy[node] = 0;
            return;
        }

        push(node);

        int mid = (l + r) / 2;

        if (pos <= mid)
            remove(node * 2, l, mid, pos);
        else
            remove(node * 2 + 1, mid + 1, r, pos);

        pull(node);
    }

    // Find the largest x such that f[x] == 0.
    int findRightmostZero() {
        if (mn[1] > 0 || mx[1] < 0)
            return -1;

        return findRightmostZero(1, 0, n - 1);
    }

    int findRightmostZero(int node, int l, int r) {
        if (l == r)
            return l;

        push(node);

        int mid = (l + r) / 2;

        // Search right side first
        if (mn[node * 2 + 1] <= 0 &&
            mx[node * 2 + 1] >= 0) {

            return findRightmostZero(
                node * 2 + 1,
                mid + 1,
                r
            );
        }

        return findRightmostZero(
            node * 2,
            l,
            mid
        );
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> cnt(N);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    SegTree st(N);

    vector<int> B;
    B.reserve(N);

    for (int i = 0; i < N; i++) {

        // Find largest value that can currently be placed.
        int x = st.findRightmostZero();

        if (x == -1) {
            cout << "No\n";
            return 0;
        }

        B.push_back(x);

        cnt[x]--;

        // If there are no more copies of x,
        // remove x from the candidates.
        if (cnt[x] == 0) {
            st.remove(x);
        }

        // x is now a smaller element for every y > x.
        st.add(x + 1, N - 1, 1);
    }

    cout << "Yes\n";

    for (int x : B) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}