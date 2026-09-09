#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<ll>> adj;
		 // B    W
vector<pair<ll , ll>> answer;
string s;

void dfs(ll u , ll parent){
	if(s[u - 1] == 'B'){
		answer[u].first = 1;
		answer[u].second = 0;
	}else {
		answer[u].first = 0;
		answer[u].second = 1;
	}
	for(ll v : adj[u]){
		if(v == parent) continue;

		dfs(v , u);
		answer[u].first += answer[v].first;
		answer[u].second += answer[v].second;
	}
}

void solve(){
	ll n;
	cin>> n;
	adj.clear();
	adj.resize(n + 1);
	answer.clear();
	answer.resize(n + 1);
	//   2 3 4 5 6 7 
	//   1 1 2 3 3 5
	for(ll i = 2; i<=n ; i++){
		ll x; cin>> x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}

	cin>> s;

	dfs(1 , 0);
	ll ans =  0;
	for(ll u = 1; u <=n; u++){
		if(answer[u].first == answer[u].second){
			ans++;
		}
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t;
	cin>> t;
	while(t--) solve();

	return 0;
}
