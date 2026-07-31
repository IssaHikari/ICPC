#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }

    int mn = INT_MAX; 
    int mx = 0;      

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            mn = min(mn, v[i]);
        } else {
            mx = max(mx, v[i]);
        }
    }
    if (mx + 1 < mn) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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