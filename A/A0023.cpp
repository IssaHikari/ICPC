#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin>> n;
  vector<int> v(n);
  for(int i = 1;i<=n;i++){
    v[i-1] = i;
  }
  int cpt = 0;
  for(int i = 1; i <= n - 1;i++){
     cpt = (cpt + i) % n;
    cout<<v[cpt]<<" ";
  }
  cout<<"\n";
  return 0;
}
