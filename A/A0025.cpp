#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n , k;
  cin>> n >> k;
  vector<int> v(n);
  for(int i = 0; i<n;i++) cin>>v[i];
  int l = k , r = 0 , sum = 0;
  for(int i= 0; i<k;i++){
    sum+= v[i];
  }
  int mx = sum;
  while (k > r){
    l--;
    sum -= v[l];
    sum += v[n - r - 1];
    r++;
    mx = max(mx  , sum);
  }
  cout<<mx<<endl;
  return 0;
}
