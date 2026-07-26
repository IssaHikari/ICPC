#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n , k;
    cin>> n >> k;
    int ans = 1;
     int MOD = 1e9+ 7;
    for(int i =0; i <k;i++){
        ans = (n * n) % MOD;
    }
    cout<< ans <<endl;
}

int mian(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>> t;
    while(t--) solve();
    return 0;
}