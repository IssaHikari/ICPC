#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve(){
    ll n; cin>> n;
    vector<ll> v(n);
    map<ll,ll> mp;
    ll nbr_odd= 0 , nbr_even =0 ;
    for(int i =0 ; i< n; i++){
        cin>> v[i];
        if(v[i]%2!=0){
            nbr_odd++;
        }else {
            mp[(v[i]/2)%2]++;
        }
    }

    for(auto [number  , count] : mp){
        nbr_even = max(nbr_even , count);
    }
    cout<< max(nbr_odd , nbr_even) << endl;   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>> t;
    while(t--) solve();

    return 0;
}