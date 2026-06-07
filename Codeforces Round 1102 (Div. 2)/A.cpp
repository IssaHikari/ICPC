#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin() , a.end() , greater<int>());
    bool check = false;
    if(n == 2) {
        cout <<a[0]<<" "<<a[1]<<"\n";
        return;
    }else {
        for (int i = 0; i <= n - 3; i++) {
            if(a[i] % a[i + 1] != a[i + 2]){
                check = true;
                break;
            }
        }
    }

    if(!check) cout<<a[0] <<" "<<a[1]<<"\n";
    else cout<<-1<<"\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}