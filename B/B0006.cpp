#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>> n;
  vector<int> a(n);
  for(ll i = 0; i<n;i++) cin>>a[i];
  unordered_set<int> suffix_set;
  int r = n;
  while (r > 0 && !suffix_set.count(a[r - 1])){
    r--;
    suffix_set.insert(a[r]);
  }

  if(r == 0){
    cout<< 0<<"\n";
    return 0;
  }

  int min_delete = r;
  unordered_set<int> prefix_set;
  for(int l = 0; l < n; l++){
    if (prefix_set.count(a[l])){
      break;
    }
    prefix_set.insert(a[l]);

    while (r < n && suffix_set.count(a[l])) {
      suffix_set.erase(a[r]);
      r++;
    }
    
    int current_delete = max(0 , r - 1 - l);
    min_delete  = min(current_delete , min_delete);
  }
  cout<<min_delete<<endl;
  return 0;
}
