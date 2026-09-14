#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n;

    map<int, int> mp_a;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp_a[x]++;
    }

    cin >> m;

    map<int, int> mp_b;

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        mp_b[x]++;
    }

    bool found = false;

    for(auto [x, freq] : mp_b) {
        if(mp_a[x] < freq) {
            cout << x << " ";
            found = true;
        }
    }

    if(!found) {
        cout << -1;
    }

    cout << '\n';

    return 0;
}