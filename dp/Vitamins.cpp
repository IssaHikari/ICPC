#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>> n;
    const long long INF = 1e18;
    vector<long long> dp(8 , INF);
    dp[0] = 0;
    for(int i = 0; i< n;i++){
        long long cost;
        string s;
        cin>> cost>> s;

        int juiceMask = 0;
        for(char ch : s){
            if(ch == 'A') juiceMask |= 1;
            if(ch == 'B') juiceMask |= 2;
            if(ch == 'C') juiceMask |= 4;
        }
        for(int mask = 0; mask< 8 ;mask++){
            if(dp[mask] < INF){
                int newMask = mask | juiceMask;
                dp[newMask] = min(dp[newMask] , cost + dp[mask]);
            }
        }
    } 
    if (dp[7] >= INF) cout << -1 << "\n";
    else cout << dp[7] << "\n";
}