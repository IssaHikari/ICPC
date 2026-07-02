// #include<bits/stdc++.h>

// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n; 
//     cin >> n;
//     vector<int> s(n);
//     vector<int> vec_lcm(n-1);
//     for(int i = 0; i < n; i++) cin >> s[i];
//     for(int i = 0;i < n-1; i++){
//         vec_lcm[i] = s[i] / gcd(s[i] , s[i+1]) * s[i+1];
//     }
//     int ans = vec_lcm[0];
//     for(int i = 0;i< n-1 ; i++){
//         ans = gcd(ans,vec_lcm[i]);
//     }

//     cout<< ans << endl;


//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                mp[p].push_back(cnt);
            }
        }

        if (x > 1) {
            mp[x].push_back(1);
        }
    }

    long long ans = 1;

    for (auto &[prime, vec] : mp) {
        if ((int)vec.size() < n - 1)
            continue;

        if ((int)vec.size() == n - 1) {
            sort(vec.begin(), vec.end());
            ans *= 1LL * pow(prime, vec[0]);
        }
        else { 
            sort(vec.begin(), vec.end());
            ans *= 1LL * pow(prime, vec[1]);
        }
    }

    cout << ans << '\n';

    return 0;
}