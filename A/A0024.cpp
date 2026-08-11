#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n , k;
  cin>> n>> k;
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin>>v[i];
  int l = 0, mx = 0 , sum = 0;
  for(int i = 0; i<k;i++){
    sum += v[i];
  }
  mx = sum;
  for(int r = k; r<n;r++){
    sum -= v[l];
    sum += v[r];
    l++;
    mx = max(sum , mx);
  }
  cout<<mx<<endl;
  return 0;
}
