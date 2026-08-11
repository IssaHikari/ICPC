#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n , t;
  cin>>n >> t;
  vector<long long> v(n);
  for(long long i = 0; i< n;i++) cin>>v[i];
  long long mx = 0;
  long long sum = 0;
  long long l = 0;
  
  for(long long r = 0; r<n;r++){
    sum += v[r];

    while (sum > t) {
      sum -= v[l];
      l++;
    }

    mx = max(mx , r - l + 1);
  }
  cout<< mx <<endl;
  return 0;
}
