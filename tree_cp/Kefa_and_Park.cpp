#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> a;
vector<vector<ll>> adj;
ll ans;
ll M;


void dfs( ll u , ll parent , ll nbr_cat){
  nbr_cat += a[u];
  if (nbr_cat > M)
    return;
  for(ll v : adj[u]){

    if (v == parent)
      continue;
    if (a[v] == 1)
      dfs(v , u , nbr_cat);
    else 
      dfs(v, u , 0);
  }
  if (u != 1 && adj[u].size() == 1 && nbr_cat <= M)
    ans++;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n , m ;
  cin>> n >> m;
  M = m;
  adj.resize(n + 1);
  a.resize(n + 1);
  for(int i = 1; i <= n; i++) cin>> a[i];

  for(int i = 1; i <= n - 1; i++){
    ll x, y ;
    cin>> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  dfs(1 , 0 , 0);

  cout<< ans <<endl;

  return 0;
}
