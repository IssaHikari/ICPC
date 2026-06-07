// #include<bits/stdc++.h>

// using namespace std;

// void solve() {
//     int n , m;
//     cin >> n >> m;
//     string s;
//     cin >> s;
//     vector<int> a(m);
//     for (int i = 0; i < m; i++){
//      cin >> a[i];
//     // a[i]--;
//     }    
//     map<char, int> mp;
//     for (char c = 'a'; c <= 'z'; c++) {
//         mp[c] = 0;
//     }
//     for (char c : s) {
//         mp[c]++;
//     }
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < a[i]; j++) {
//             mp[s[j]]++;
//         }
//     }
//     for (char c = 'a'; c <= 'z'; c++) {
//         cout << mp[c] << " ";
//     }
//     cout << "\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int t;
//     cin >> t;
//     while(t--) solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<ll> diff(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        diff[0]++;
        diff[x]--;
    }

    vector<ll> cnt(n);
    cnt[0] = diff[0];

    for (int i = 1; i < n; i++) {
        cnt[i] = cnt[i - 1] + diff[i];
    }

    vector<ll> ans(26, 0);

    for (int i = 0; i < n; i++) {
        ans[s[i] - 'a'] += cnt[i] + 1;
    }

    for (int i = 0; i < 26; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}