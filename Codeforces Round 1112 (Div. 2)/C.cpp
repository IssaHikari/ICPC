#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    if ((n & (n - 1)) != 0) {
        cout << -1 << '\n';
        return;
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = i ^ j;

            if (i & 1) {
                val ^= x;
            }

            cout << val << (j + 1 == n ? '\n' : ' ');
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}