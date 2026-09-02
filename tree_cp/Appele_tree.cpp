#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<ll>> adj;
vector<ll> possible;

void dfs(ll u , ll parent){
    for(ll v : adj[u]){
        if(v == parent) continue;
        dfs(v , u);
        possible[u] += possible[v];
    }
    if(adj[u].size() == 1 && u != 1){
        possible[u] = 1;
    }
}

void solve(){
    ll n; cin>> n;
    adj.clear();
    adj.resize(n + 1);
    possible.clear();
    possible.resize(n + 1);
    for(int i = 1; i < n; i++){
        ll u , v;
        cin>> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1 , 0);
    ll q; cin>> q;

    for(ll i =0 ; i< q; i++){
        ll x , y;
        cin>> x >> y;
        cout<< possible[x] * possible[y] << "\n";
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t; cin>> t;

    while(t--){
        solve();
    }
    return 0;
}