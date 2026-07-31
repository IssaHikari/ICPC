#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin>> n;
    string s;
    cin>> s;
    vector<int> v(n);
    for(int i = 0; i< n;i++) cin>> v[i];
    long long mn = LLONG_MAX;
    for(int i = 0; i< n -1; i++){
        if(s[i] == 'R' && s[i+1] == 'L'){
            long long avrg = (v[i+1] - v[i]) / 2;
            mn = min(avrg , mn);
        }
    }
    if(mn == LLONG_MAX){
        cout<< -1 <<endl;
    }else {
        cout<< mn << endl;
    }
    return 0;
}
