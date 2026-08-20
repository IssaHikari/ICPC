#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>> n;
    vector<int> v(n);

    for(int i = 0; i < n ; i++) cin>>v[i];
    int best_l = 0 , best_r = 0;
    int mn = 1e9;
    for(int r = 0; r<n - 1;r++){
        int t = abs(v[r] - v[r+1]);
        if( t < mn){
            mn = t; 
            best_l = r;
            best_r = r + 1;
        }
    }
    if(abs(v[0] - v[0]) < mn){
        cout<<0<<
    }
    return 0;
}