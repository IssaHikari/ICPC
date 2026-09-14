#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>> n;
    vector<int> v(n + 1);
    vector<int> wrong;
    for(int i = 1; i <= n; i++){
        cin>> v[i];
        if(v[i] != i) wrong.push_back(i);
    }

    sort(wrong.begin() , wrong.end());

    for (int i = 0; i < (int)wrong.size(); i++) {
         if (v[wrong[i]] != wrong[i]){ 
            int olIndex = wrong[wrong.size() - 1 - i];
            if (v[olIndex] != wrong[i]) {
                 cout << "NO\n"; return; 
            } 
        } 
    } 
    cout << "YES\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>> t;

    while(t--) 
        solve();

    return 0;
}