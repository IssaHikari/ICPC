#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>> s;
    if(islower(s[0])){
        s[0] = toupper(s[0]);   
    }
    cout<< s<<endl;
    return 0;
}