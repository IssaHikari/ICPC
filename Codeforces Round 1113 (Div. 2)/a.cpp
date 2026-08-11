#include <bits/stdc++.h>
using namespace std;


string bobsMove(string t) {
    int n = t.size();
    for (int i = 0; i < n - 1; i++) {
        if (t[i] > t[i+1]) {
            return t.substr(0, i) + t.substr(i+1); 
        }
    }
    return t.substr(0, n-1);
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    string best = "";
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            string afterAlice = s.substr(0, i) + s.substr(i+1);
            string afterBob = bobsMove(afterAlice);

            if (!found || afterBob > best) {
                best = afterBob;
                found = true;
            }
        }
    }

    cout << best << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}