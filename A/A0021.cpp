#include<bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int firstR = -1 , lastL = -1;
    for(int i =0; i <n;i++){
        if(s[i] == 'R' && firstR == -1) firstR = i;
        if(s[i] == 'L') lastL = i;
    }

    if(firstR == -1 || lastL == -1){
        cout<< -1 <<endl;
        return;
    }
    if(firstR < lastL){
        cout<< 0<<endl;
        return;
    }
    cout<< (lastL + 1) <<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>> t;
    while(t--) solve();
    return 0;
}
