#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

vector<vector<ll>> x;
bool visited[105];
ll ans = 1;

void dfs(ll n , ll parent) {
    if(n!=parent){
        ans *= 2;
    }
    visited[n] = true;
    for (int i = 0; i < x[n].size();i++){
        ll lol = x[n][i];
        if(!visited[lol]) {
            dfs(lol , parent);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    x.resize(n + 5);
    for (int i = 0; i < m; i++) {
        ll a , b;
        cin >> a >> b;
        x[a].pb(b);
        x[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i , i);
        }
    }

    cout << ans << endl;


    return 0;
}