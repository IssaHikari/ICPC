#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long l = 1, r = 2000000000LL;

    while (l < r) {
        long long mid = l + (r - l + 1) / 2;

        if ((__int128)mid * (mid - 1) / 2 <= n)
            l = mid;
        else
            r = mid - 1;
    }

    long long pairs = l * (l - 1) / 2;

    long long ans = l + (n - pairs);

    cout << ans << '\n';

    return 0;
}