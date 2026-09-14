#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int MAXN = 200000;

ll fact[MAXN + 1];
ll inv[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;

    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv[1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);

        for (auto &x : a)
            cin >> x;

        sort(a.begin(), a.end());

        vector<ll> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] + a[i]) % MOD;
        }

        ll ans = 0;

        for (int i = 0; i < n - 1; i++) {

            ll k = n - 1 - i;
            ll cost = (suffix[i + 1] - (k % MOD) * (a[i] % MOD)) % MOD;
            if (cost < 0)
                cost += MOD;
            ll ways = fact[n - 1] * inv[k] % MOD;
            ans = (ans + cost * ways) % MOD;
            
        }

        cout << ans << '\n';
    }

    return 0;
}