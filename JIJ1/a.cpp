#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s ;
    cin>> s;
    int x = s.length() - 1;
    if(s[x] == 'e'){
        s += 'r';
    }else {
        s += "er";
    }
    cout<< s << endl;
    return 0;
}