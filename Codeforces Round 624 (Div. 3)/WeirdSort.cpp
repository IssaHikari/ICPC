#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isSorted(vector<ll>& a) {
    for (ll i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n), p(m);

        for (ll i = 0; i < n; i++)
            cin >> a[i];

        for (ll i = 0; i < m; i++) {
            cin >> p[i];
            p[i]--;             
        }

        bool changed = true;

        while (changed) {
            changed = false;

            for (ll i = 0; i < m; i++) {
                if (a[p[i]] > a[p[i] + 1]) {
                    swap(a[p[i]], a[p[i] + 1]);
                    changed = true;
                }
            }
        }

        if (isSorted(a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}