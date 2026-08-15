#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<ll> s;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s.insert(x);
    }

    ll cur = 0;
    ll ans = 0;

    while (!s.empty()) {

        auto it = s.lower_bound(cur);

        ll right = LLONG_MAX;

        if (it != s.end())
            right = *it;

        ll left = LLONG_MAX;

        if (it != s.begin()) {
            auto p = prev(it);
            left = *p;
        }

        ll next;

        if (left == LLONG_MAX) {
            next = right;
        }
        else if (right == LLONG_MAX) {
            next = left;
        }
        else {
            ll dl = abs(cur - left);
            ll dr = abs(right - cur);

            if (dl <= dr)
                next = left;
            else
                next = right;
        }

        ans += abs(cur - next);
        cur = next;

        s.erase(next);
    }

    cout << ans << '\n';
}