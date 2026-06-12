#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        sort(a.begin(), a.end());

        vector<int> grp(n);
        vector<int> sz;

        int id = 0;
        grp[0] = 0;
        sz.push_back(1);

        for (int i = 1; i < n; i++) {
            if (a[i] - a[i-1] <= k) {
                grp[i] = id;
                sz[id]++;
            } else {
                grp[i] = ++id;
                sz.push_back(1);
            }
        }

        int m = sz.size();

        vector<int> parity(m);
        int xr = 0;

        for (int i = 0; i < m; i++) {
            parity[i] = sz[i] & 1;
            xr ^= parity[i];
        }

        bool ok = false;

        for (int i = 0; i < n; i++) {
            int g = grp[i];

            int new_parity = ((sz[g] - 1) & 1);

            int new_xr = xr ^ parity[g] ^ new_parity;

            if (new_xr == 0) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}