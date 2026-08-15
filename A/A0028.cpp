#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

bool valid(string s) {
    for (int i = 0; i + 2 < s.size(); i++) {
        if (s[i] != '?' && s[i + 2] != '?' && s[i] == s[i + 2])
            return false;
    }
    return true;
}

int solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    long long ans = 0;

    // Try all 4 possible alternating patterns
    for (int oddStart = 0; oddStart <= 1; oddStart++) {
        for (int evenStart = 0; evenStart <= 1; evenStart++) {

            bool ok = true;

            for (int i = 0; i < n; i++) {

                int expected;

                if (i % 2 == 0)
                    expected = oddStart ^ (i / 2 % 2);
                else
                    expected = evenStart ^ (i / 2 % 2);

                if (s[i] != '?' && s[i] - '0' != expected) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();
}
