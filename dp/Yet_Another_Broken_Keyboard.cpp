#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n ,k;
    cin>> n >> k;
    string s;
    cin>>s;
    vector<bool> allowed(26 , false);
    for(int i= 0; i< k;i++){
        char c;
        cin>>c;
        allowed[c - 'a'] = true;
    }
    long long dp = 0;
    long long ans = 0;
    for(int i = 0 ; i < n; i++){
        if(allowed[s[i] - 'a']) dp++;
        else dp = 0;
        ans+=dp;
    }
    cout<< ans <<endl;
    return 0;
}