#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ll n , k;
  scanf("%lld %lld" , &n , &k);
  vector<ll> v(n);
  for(int i = 0; i<n; i++) scanf("%lld" , &v[i]);
  ll l = 0;
  vector<int> cnt(1e6 , 0);
  ll bestLen = 0 , bestL = 0 , distinct = 0; 
  for(ll r = 0; r<n; r++){
    cnt[v[r]]++;
    if(cnt[v[r]] == 1) distinct++;

    while (distinct > k) {
      cnt[v[l]]--;
      if(cnt[v[l]] == 0) distinct--;
      l++;
    }
    
    if(bestLen < r - l + 1){
      bestLen = r - l + 1;
      bestL = l;
    }
  }
  printf("%lld %lld" , bestL + 1 , bestLen + bestL);
  return 0;
}
