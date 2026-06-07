#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];

        for (int start = 0; start < n; start++) {

            vector<ll> a(n - 1);

            for (int i = 0; i < n - 1; i++)
                a[i] = h[(start + i) % n];

            vector<ll> pref(n - 1), suff(n - 1);

            pref[0] = a[0];
            for (int i = 1; i < n - 1; i++)
                pref[i] = min(pref[i - 1], a[i]);

            suff[n - 2] = a[n - 2];
            for (int i = n - 3; i >= 0; i--)
                suff[i] = min(suff[i + 1], a[i]);

            ll cur = *max_element(a.begin(), a.end());

            for (int i = 0; i < n - 1; i++)
                cur += min(pref[i], suff[i]);

            cout << cur << " ";
        }

        cout << '\n';
    }
}