#include<bits/stdc++.h>

using namespace std;


vector<vector<int>> adj;

// vector<int> subtree;
 
// void dfs_sub(int u , int parent){
// 	 subtree[u] = 1;
// 	 for(int v : adj[u]){
// 		 if(v == parent) continue;
		 
// 		 dfs_sub(v , u);
// 	 }
// 	 subtree[parent] += subtree[u];
// }

void inorder(int u , int parent){
    for (int v : adj[u]){
        if (v==parent) continue;
        inorder(v, u);
        cout<<v<<endl;
        cout<<u<<endl;
    }
}

// vector<int> depth;

// int maxDiameter = 0;
// int nextFather = 0;
// void diameter(int u , int parent , int diam){
//     if(diam > maxDiameter){
//         maxDiameter = diam;
//         nextFather = u;
//     }
//     for(int v : adj[u]){
//         if(v == parent)
//             continue;

//         diameter(v, u , diam + 1);

//     }
// }

// void dfs_depth(int u , int parent){
//     for(int v : adj[u]){
//         if(v == parent)
//             continue;
        
//         depth[v] = depth[u] + 1;
//         dfs_depth(v , u);
//     }
// }
// vector<int> dp;
// void sub_tree(int u , int parent){
//     dp[u] = 1;
//     for(int v : adj[u]){
//         if(v == parent){
//             continue;
//         }
//         sub_tree(v, u);
//     }
//     dp[parent] += dp[u];
// }
// vector<int> value;
// vector<int> dp_sum;
// void sub_tree(int u , int parent){
//     dp_sum[u] = value[u];
//     for(int v : adj[u]){
//         if(v == parent){
//             continue;
//         }
//         sub_tree(v, u);
//         dp_sum[u] += dp_sum[v];
//     }
// }

// void dfs(int u , int parent , int depth){

//     cout<<"node : " << u <<
//         ",  depth :"<< depth<<endl;

//     for(int v : adj[u]){
//         if(v == parent)
//             continue;
        
//         dfs(v , u , depth + 1);
//     }
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>> n;
    adj.resize(n + 1);
    for(int i = 0; i<n - 1;i++){
        int u , v;
        cin>> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //int depth = 0;
   // dfs(1 , 0 , depth);

    // depth.resize(n + 1);
    // dfs_depth(1 , 0 );
    // for(int v : depth){
    //     cout<<v<<endl;
    // }
    // //cout<<"the depth :"<<depth<<endl;

    // dp.resize(n + 1);
    // sub_tree(1 , 0);
    // for(int i = 0 ; i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<"\n";

    inorder(1 , 0);

    // for(int u = 1; u <= n ; u++){
    //     cout<< u << ": ";

    //     for(int v : adj[u]){
    //         cout<<v<< " ";
    //     }
    //     cout<<"\n";
    // }

    // dfs_sub(1 , 0);
    // for (int v : subtree){
    //     cout<<v<<endl;
    // }
    return 0;
}