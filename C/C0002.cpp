#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> u(n) , v(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i] >> v[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (u[i] == u[j] || v[i] == v[j]) {
                ans++;
            }
        }
    }
}

int main() {
    int t;
    cin>> t;
    while (t--){
        solve();
    }
    return 0;
}