#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  ll n  = s.size();
  vector<ll> prefix(n , 0);
  for(int i = 1 ; i<n;i++){
    prefix[i] = prefix[i - 1];
    if(s[i] == s[i - 1]) prefix[i]++;
  }
  ll m ;
  cin>> m;
  for(int i =0 ; i<m;i++) {
    int r ,l ; // 1 6 -> 5
    cin>> r >> l;
    cout<< prefix[l - 1] - prefix[r - 1]<<endl;
  }





  // ll m; cin>> m;
  // for(int i = 0; i<m;i++){
  //   ll r , l;
  //   cin>>r >>l;
  //   int ans = 0;
  //   // - - - - - -
  //   // 1 2 3 4 5 6 
  //   // 0 1 2 3 4 5 
  //   // 3 4 - > 2 3
  //   // 1 6 - > 0 5
  //   r -= 1;
  //   l -= 1;
  //   while(r < l){
  //     if(s[r] == s[r + 1]) ans++;
  //     r++;
  //   }
  //   cout<<ans<<endl;
  // }
  return 0;
}
