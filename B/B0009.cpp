#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n , k;
  cin>> n>> k;
  vector<int> h(n);
  for(int i = 0; i<n;i++) cin>>h[i];
  int sum = 0 ,ans =0 , l = 0 , res = 0;
  for(int i = 0;i<k;i++){
    sum += h[i];
  }
  ans = sum;
  for(int r = k; r <n;r++){
    sum -= h[l];
    sum += h[r];
    if(sum < ans){
      ans = sum;
      res = l + 1;
    }
    l++;
  }
  cout<<res + 1<<endl;
  return 0;
}
