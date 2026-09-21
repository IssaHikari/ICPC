#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s, t;

    cin >> n;
    cin >> s;
    cin >> t;

    for (int i = 0; i < n; i++) {
        if (t[i] != '*' && s[i] != t[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}