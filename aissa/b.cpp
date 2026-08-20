#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    ll firstA, firstB;

    cin >> firstA;

    for (int i = 1; i < n; i++) {
        ll x;
        cin >> x;
    }

    cin >> firstB;

    for (int i = 1; i < m; i++) {
        ll x;
        cin >> x;
    }

    ll attacksByBea = firstB + m - 1;
    ll attacksByVer = firstA + n - 1;

    if (attacksByBea <= attacksByVer)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
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