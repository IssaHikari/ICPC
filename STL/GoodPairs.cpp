#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n; 
        vector<ll> v(n);
        for(int i = 0; i < n; i++) cin>> v[i];
        pair<ll , ll> p = {0 , 0};
        vector<ll> t;
        t = v;
        sort(t.begin() , t.end());
        ll mn = t[0] , mx = t[t.size() - 1];
        for(int i = 0; i < n; i++){
            if(v[i] == mn) {
                p.first = i;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(v[i] == mx) {
                p.first = i;
                break;
            }
        }
        cout<< p.first + 1 << " " << p.second + 1 <<endl;
    }

    return 0;
}