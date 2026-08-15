#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;


ll power(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}


ll comb(ll n, ll k) {
    if (k < 0 || k > n)
        return 0;

    ll res = 1;

    for (ll i = 1; i <= k; i++) {
        res = res * (n - i + 1) % MOD;
        res = res * power(i, MOD - 2) % MOD;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;

    ll sum = 0;
    ll sumSq = 0;

    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;

        x %= MOD;

        sum = (sum + x) % MOD;
        sumSq = (sumSq + x * x) % MOD;
    }


    ll c1 = comb(N - 1, K - 1);


    ll c2 = comb(N - 2, K - 2);


    ll pairs = (sum * sum % MOD - sumSq + MOD) % MOD;


    pairs = pairs * power(2, MOD - 2) % MOD;

    ll ans = 0;


    ans = (ans + c1 * sumSq) % MOD;


    ans = (ans + 2 * c2 % MOD * pairs) % MOD;

    cout << ans << '\n';

    return 0;
}