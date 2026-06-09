#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        const int MULT = n + 2;
        const int INF  = MULT * (n + 2);

        vector<int> dp(n+1, INF), ndp(n+1, INF);

        vector<vector<int>> back(n+1, vector<int>(n+1, -1));

        dp[0] = 0;  

        for(int i = 0; i < n; i++){
            fill(ndp.begin(), ndp.end(), INF);
            for(int j = 0; j <= i; j++){
                if(dp[j] == INF) continue;
                int val = dp[j];
                int d   = val % MULT;
                int m   = val / MULT;

                if(d + 1 <= k){
                    int nv = m * MULT + (d + 1);
                    if(nv < ndp[j]){
                        ndp[j] = nv;
                        back[i+1][j] = 0*(n+1) + j;
                    }
                }

                if(s[i] == '('){
                    if(val < ndp[j+1]){
                        ndp[j+1] = val;
                        back[i+1][j+1] = 1*(n+1) + j;
                    }
                } else {
                    if(j > 0){  
                        int nv = (m+1)*MULT + d;
                        if(nv < ndp[j-1]){
                            ndp[j-1] = nv;
                            back[i+1][j-1] = 1*(n+1) + j;
                        }
                    } else {   
                        if(val < ndp[0]){
                            ndp[0] = val;
                            back[i+1][0] = 1*(n+1) + 0;
                        }
                    }
                }
            }
            swap(dp, ndp);
        }

  
        int best_j = 0;
        for(int j = 1; j <= n; j++)
            if(dp[j] < dp[best_j]) best_j = j;

    
        string res(n, '0');
        int cur_j = best_j;
        for(int i = n; i >= 1; i--){
            int b      = back[i][cur_j];
            int choice = b / (n+1);
            int prev_j = b % (n+1);
            res[i-1]   = (choice == 0) ? '1' : '0';
            cur_j      = prev_j;
        }

        cout << res << "\n";
    }
    return 0;
}