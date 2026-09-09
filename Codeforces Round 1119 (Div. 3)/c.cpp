#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    ll n;
    cin >> n;

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll bL = -1;
    ll bR = -1;
    ll bLen = 0;

    ll start = -1;

    for (int i = 0; i < n; i++) {

        if (v[i] != 0) {

            if (start == -1) {
                start = i;
            }

            if (i - start + 1 > bLen) {
                bLen = i - start + 1;
                bL = start;
                bR = i;
            }

            if (v[i] == 1) {
                start = i;
            }
        }
    }


    if (bL != -1 && bR != -1) {

        v[bL] = 1;

        v[bR] = 1;

        for (int i = bL + 1; i < bR; i++) {
            if (v[i] == -1)
                v[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == -1)
            v[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}

