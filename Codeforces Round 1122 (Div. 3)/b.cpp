#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    if (a >= b) {
        cout << a - b + c << '\n';
    } else {
        ll d = b - a;
        cout << max(d, c - d) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}