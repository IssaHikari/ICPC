#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    ll n ;
    cin>> n;
    vector<ll> v(n);
    for(int i =0 ;i < n;i++) cin>>v[i];  
    cout<<gcd(v[0] , v[n - 1])<<endl;  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin>> t;
    while(t--) solve();

    return 0;
}
