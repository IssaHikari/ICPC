#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    ll n; 
    cin>> n;
    ll sum = n;
    while(n > 1){
      n /= 2;
      sum += n;
    }
  cout<< sum <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>> t;
    
    while(t--) solve();

    return 0;
}
