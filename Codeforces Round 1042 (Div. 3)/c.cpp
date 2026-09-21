#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;

    map<ll, int> cntS, cntT;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        ll r = x % k;
        ll key = min(r, k - r);

        cntS[key]++;
    }

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        ll r = x % k;
        ll key = min(r, k - r);

        cntT[key]++;
    }

    if (cntS == cntT)
        cout << "YES\n";
    else
        cout << "NO\n";
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
