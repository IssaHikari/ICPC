#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin>> n;
  vector<int> v(n + 1);
  for (int i = 1; i<= n; i++){
    cin>> v[i];
  }

  int ans =0;
  // 1  2  3  4  5 index
  //-1  1  2  1 -1
  //
  for(int i = 1; i<=n;i++){
    int cur = i;
    int depth = 1;

    while (v[cur] != -1){
      cur = v[cur];
      depth++;
    }
    ans = max(ans , depth);
  }

  cout<< ans <<endl;
}
