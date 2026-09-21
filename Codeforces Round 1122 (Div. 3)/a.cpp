#include<bits/stdc++.h>

using namespace std;

void solve(){
    int  n;
    cin>> n;
    int a1 , a2 , a3;
    cin>> a1 >> a2 >> a3;
    int x = min(min(a1 , a2) ,a3);
    cout<< n - x << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>> t;

    while(t--) solve();

    return 0;
}