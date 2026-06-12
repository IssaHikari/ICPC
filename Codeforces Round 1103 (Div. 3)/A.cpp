#include<bits/stdc++.h>

using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i  = 0; i< n; i++) cin >> h[i];
    sort(h.begin() , h.end());
    cout<< (h[n-1] + 1) - h[0] << endl;


}  

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>> t;
    while(t--) solve();
    return 0;
}