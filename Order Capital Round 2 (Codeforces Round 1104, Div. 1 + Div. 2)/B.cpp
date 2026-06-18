// #include<bits/stdc++.h>

// using namespace std;

// void solve(){
//     int n;
//     cin >> n;
//     vector<int> a(n) , b(n);
//     int ans = 0;
//     for(int i = 0; i< n; i++) cin>>a[i];
//     for(int i = 0; i < n; i++) cin>>b[i];
//     int nn = n;
//     while(n > 0){
//         int indexMax = 0;
//         for(int i = 1; i< n;i++){
//             if(a[indexMax]<a[i]){
//                 indexMax = i;
//             }
//         }

//         for(int j = indexMax; j < n - 1;j++){
//             int temp = a[j];
//             a[j] = a[j + 1];
//             a[j + 1] = temp;
//             ans++;
//         }
//         n--;
//     }

//     for(int i = 0;i < nn; i++){
//         if(b[i] < a[i]){
//             cout<< -1 <<endl;
//             return;
//         }
//     }
//     cout << ans << endl;

// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while(t--) solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> pos(n);
    vector<bool> used(n, false);

    for (int i = 0; i < n; i++) {
        int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

        while (j < n && used[j]) j++;

        if (j == n) {
            cout << -1 << '\n';
            return;
        }

        pos[i] = j;
        used[j] = true;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pos[i] > pos[j])
                ans++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}