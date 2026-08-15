#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while (t--){
    vector<int> v(3);
    cin>>v[0]>>v[1]>>v[2];
    sort(v.begin() , v.end());
    int mn = min(v[2] - v[0] , v[1]);
    cout<<mn<<endl;
  }
  return 0;
}
