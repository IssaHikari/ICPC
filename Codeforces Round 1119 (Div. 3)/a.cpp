#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n , k , ans = 0;
        cin>> n >> k;
        string s;
        cin>> s;
            // 10 10 10 10
        bool isfree;
        for(int i = 0; i < n; i+=k){
            isfree = true;
            for(int j = i; j < i + k; j++){
                if(s[j] == '0'){
                    isfree = false;
                    break;
                }
            }
            if(isfree) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}