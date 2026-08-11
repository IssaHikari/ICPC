#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>> n;
  string s;
  cin>> s;
  
  int countH = 0;

  for(int i = 0;i < n; i++){
    if(s[i] == 'H') countH++;
  }
  
  if(countH == 0 || countH == n){
    cout<< 0<<endl;
    return 0;
  }

  int curT = 0;

  for(int i = 0 ; i < countH ;i++){
    if(s[i] == 'T') curT++;
  }

  int mn = curT;
  string ss = s + s;
  for(int start = 1 ; start < n;start++){
    if(ss[start - 1] == 'T') curT--;

    if(ss[start + countH - 1] == 'T') curT++;

    mn = min(mn  , curT);
  }

  cout<< mn <<endl;

  return 0;
}
