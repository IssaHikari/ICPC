#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> freq(m + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    vector<int> suf(m + 2, 0);
    for (int x = m; x >= 1; x--) {
        suf[x] = suf[x + 1] + freq[x];
    }
    int ans = 0;
    for (int x = 1; x <= m; x++) {
        int temp = suf[x];
        if (2 * x <= m) {
            temp += freq[2 * x];
        }
        ans = max(ans, temp);
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