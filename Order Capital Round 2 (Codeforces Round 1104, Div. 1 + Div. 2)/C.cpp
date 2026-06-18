// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// void solve() {
//     ll n; 
//     cin>> n;
//     vector<ll> a(n);
//     for(int i = 0; i<n;i++) cin>> a[i];
//     bool check = true;
//     while(check){
//         check = false;
//         for(int i = 0 ; i< n-1; i++){
//             if(a[i] > a[i+1]){
//                 ll x = a[i] + a[i + 1];
//                 a[i] = a[i+ 1];
//                 a[i+ 1] = x;
//                 check = true;
//             }
//         }
//     }
//     cout<< a[n -1]<< endl;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--) solve();

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> st;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        st.push_back(x);

        while (st.size() >= 2) {
            int m = st.size();

            if (st[m - 2] > st[m - 1]) {
                ll a = st[m - 2];
                ll b = st[m - 1];

                st.pop_back();
                st.pop_back();

                st.push_back(b);
                st.push_back(a + b);
            } else {
                break;
            }
        }
    }

    cout << st.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}