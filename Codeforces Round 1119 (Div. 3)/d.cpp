#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int cnt0 = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0)
                cnt0++;
        }

        if (cnt0 == 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int used = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 0 && used == 0) {
                cout << 'A';
                used++;
            }
            else if (a[i] == 0 && used == 1) {
                cout << 'B';
                used++;
            }
            else {
                cout << 'C';
            }
        }

        cout << '\n';
    }

    return 0;
}