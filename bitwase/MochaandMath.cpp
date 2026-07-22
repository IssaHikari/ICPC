#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n; cin>> n;
    vector<long long> v(n);
    int ans = 0;
    cin>> ans;
    for(int i = 1; i< n; i++) {
        cin>> v[i];
        ans &= v[i];
    }
    cout<< ans<< endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>> t;
    while(t--) solve();

    return 0;
}