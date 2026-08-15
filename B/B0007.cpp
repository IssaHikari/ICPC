#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    ll n = s.length();
    ll nbr_heavy = 0, ans = 0;
    
    for(ll i = 0; i <= n - 5; i++){
        if(s.compare(i, 5, "heavy") == 0){
            nbr_heavy++;
        }
        if(s.compare(i, 5, "metal") == 0){
            ans += nbr_heavy;
        }
    }
    
    cout << ans << endl;
    return 0;
}
