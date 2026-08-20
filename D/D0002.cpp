#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    ll n , q; cin>> n >> q;

    vector<ll> v(n);
    vector<ll> prefix(n+1 , 0);

    for(ll i= 0;i < n; i++) cin>>v[i];

    for(ll i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + v[i];
    }

    for(ll i = 0; i<q;i++){
        ll l , r , k;
        cin>>l >> r>> k;
        ll ans = prefix[n] - (prefix[r] - prefix[l - 1]) + (r - l + 1) * k;
        if(ans % 2 == 0) cout<< "NO\n";
        else cout<<"YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--) solve();

    return 0;
}