#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> t(n);
    for (auto &x : t) cin >> x;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += min(t[i], t[k]);

        if (i > k && t[i] >= t[k])
            ans--;

    }

    cout << ans << '\n';

    return 0;
}