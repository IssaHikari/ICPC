#include<bits/stdc++.h>

using namespace std;
void solve(){
    int k;
    cin>> k;
    vector<int> a(k);
    int count = 0; int cast = 0;
    for (int i = 0; i < k; i++){
        cin>> a[i];
        if(a[i] > 2){
            cast = 1;
        }
        if(a[i] >= 2){
            count++;
        }
    }
    if(cast == 1 || count>= 2){
        cout<< "YES"<< endl;
    }else {
        cout<< "NO"<< endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>> t;
    while(t--) solve();
}