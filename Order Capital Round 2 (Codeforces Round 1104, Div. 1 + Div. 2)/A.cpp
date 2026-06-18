#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[j] > a[i]){
                a[j] = a[i];
            }
        }
    }
    for(int i= 0; i < n;i++) ans += a[i];
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}