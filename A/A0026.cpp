#include<bits/stdc++.h>

using namespace std;

#define ll long long
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin>> n;
  vector<ll> v(n);
  for(int i = 0; i<n; i++) cin>>v[i];
  vector<ll> left(n , 1);
  for(int i = 1; i<n;i++){
    if (v[i] > v[i - 1]){
      left[i] = left[i - 1] + 1;
    }
  }
  vector<ll> right(n , 1);
  for(ll i = n - 2; i>= 0 ;i--){
    if (v[i] < v[i + 1]){
      right[i] = right[i + 1] + 1;
    }
  }
  ll ans = 1;
  for(ll i = 0 ; i<n; i++){
    ll leftPart = (i > 0) ? left[i - 1] :0;
    ll rightPart = (i < n-1) ? right[i + 1]: 0;

    if (i > 0  && i < n - 1 && v[i + 1] - v[i - 1] >= 2){
      ans = max(ans  , leftPart + rightPart + 1);
    }else {
      ans = max(ans , max(leftPart , rightPart) + 1);
    }
  }
  cout<<ans<<endl;
  return 0;
}
