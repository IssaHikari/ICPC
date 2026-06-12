#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll a, b, x;
        cin >> a >> b >> x;

        vector<pair<ll,ll>> A, B;

        ll cur = a, cost = 0;
        while (true) {
            A.push_back({cur, cost});
            if (cur == 0) break;
            cur /= x;
            cost++;
        }

        cur = b;
        cost = 0;
        while (true) {
            B.push_back({cur, cost});
            if (cur == 0) break;
            cur /= x;
            cost++;
        }

        ll ans = LLONG_MAX;

        for (auto [va, ca] : A) {
            for (auto [vb, cb] : B) {
                ans = min(ans, ca + cb + abs(va - vb));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}