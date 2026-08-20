#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n , m;
    cin>> n >> m;

    vector<string> w(n) , a(m);
    set<char> possible;
    for(int i = 0; i< n ;i++){
     cin>>w[i];
     possible.insert(w[i][0] - 'a' + 'A');
    }    
    bool ok = true;
    for(int i = 0; i< m ;i++){
        cin>>a[i];

        for(char c : a[i]){
            if(!possible.count(c))
                ok = false;
        }

    }

    cout<<(ok ? "YES\n"  : "NO\n");


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}