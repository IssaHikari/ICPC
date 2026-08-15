#include<bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin>>n;
  vector<int> a(n);
  for(int i = 0; i < n ; i++) cin>>a[i];
  vector<bool> b(n, false);
  b[a[0] - 1] = true;
  bool left = false , right = false;
  if(n == 1){
    cout<<"YES\n"; return;
  }
  for(int r = 1; r < n; r++){
    if (a[r] == 1){
      right = b[a[r]];
      if(!right){
        cout<<"NO\n"; return;
      }else {
        b[a[r] - 1] = true;
      }
    }else if(a[r] == n) {
      left = b[a[r] - 2];
      if(!left){
        cout<<"NO\n"; return;
      }else {
        b[a[r] - 1] = true;
      }
    }else {
      right =b[a[r]];
      left =b[a[r] - 2];
      if(!right && !left){
        cout<<"NO\n"; return;
      }else {
        b[a[r] - 1] = true;
      }
    }
  }
  cout<< "YES\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>> t;
  while (t--) solve();
  return 0;
}
