#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s ,ans = "";
    cin>>s;

    for(int i = 0; i< s.length();i++){
        if(s[i] == 'A') ans += 'A';
        else ans += '.';
    }

    cout<<ans<<endl;
    return 0;
}