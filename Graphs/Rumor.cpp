#include<bits/stdc++.h>

using namespace std;

long long Min_Nbr = 100005;
vector<int> adj[100005];
bool visited[100005];



void dfs (int node , vector<long long> &Ci){
    visited[node] = true ;
    Min_Nbr = min(Min_Nbr , Ci[node]);
    for (auto child : adj[node]){
        if (!visited[child]){
            dfs(child , Ci);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n , m ;
    long long total = 0;
    cin >> n >> m;
    vector<long long> Ci(n + 1);
    for(int i = 1 ; i <= n ; i++){
        cin >> Ci[i];
    }
    for(int i = 0 ; i < m ; i++){
        int  u , v ;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int j = 1 ; j <= n ; j++){
        if (!visited[j]){
            Min_Nbr = Ci[j];
            dfs(j , Ci);
            total += Min_Nbr;
        }
    }
    cout << total << endl;
    return 0;
}