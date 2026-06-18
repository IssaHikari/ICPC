#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        
        long long cnt[3] = {};
        cnt[0] = 1;
        long long prefix = 0;
        long long same_mod3 = 0;
        
        for (int i = 0; i < n; i++) {
            prefix += (s[i] == '0') ? 1 : -1;
            int mod = ((prefix % 3) + 3) % 3;
            same_mod3 += cnt[mod];
            cnt[mod]++;
        }
        
        long long total = (long long)n * (n + 1) / 2;
        long long part1 = total - same_mod3;
        
        long long part2 = 0;
        
        int i = 0;
        while (i < n) {
            int j = i + 1;
  
            while (j < n && s[j] != s[j-1]) j++;
            long long L = j - i;
            
            if (L >= 3) {

                long long max_k = (L % 2 == 1) ? L : L - 1;
                long long num_terms = (max_k - 1) / 2;
                long long sum_k = ((max_k + 1) / 2) * ((max_k + 1) / 2) - 1;
                part2 += num_terms * (L + 1) - sum_k;
            }
            i = j;
        }
        
        cout << part1 - part2 << "\n";
    }
    return 0;
}