#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    int zeros = 0;

    for (char c : s) {
        if (c == '0')
            zeros++;
    }

    if (s[0] == '1') {
        cout << zeros << '\n';
        return;
    }

    int ones_left = 0;
    int zeros_right = zeros;

    int ans = zeros;

    for (int i = 0; i < n; i++) {

        if (s[i] == '1') {
            ones_left++;
        } else {
            zeros_right--;
        }

        int cost = ones_left + zeros_right;
        ans = min(ans, cost);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}