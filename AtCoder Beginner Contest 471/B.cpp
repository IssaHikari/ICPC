#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    map<string ,int> mp;
    for(int i = 0; i<n;i++){
        string t;
        cin>>t;
        transform(t.begin() , t.end() , t.begin() , ::tolower);
        mp[t]++;
    }
    int ans = 0;
    for(auto x : mp){
        ans = max(ans , x.second);
    }
    cout<<ans<<endl;
    return 0;
}