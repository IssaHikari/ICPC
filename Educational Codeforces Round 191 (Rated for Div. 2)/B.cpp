#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p1(n), p2(n), p3(n), p4(n);

        for (int i = 0; i < n; i++)
            p1[i] = i;

        while (true) {
            p2 = p3 = p4 = p1;

            shuffle(p2.begin(), p2.end(), rng);
            shuffle(p3.begin(), p3.end(), rng);
            shuffle(p4.begin(), p4.end(), rng);

            vector<int> pos1(n), pos2(n), pos3(n), pos4(n);

            for (int i = 0; i < n; i++) {
                pos1[p1[i]] = i;
                pos2[p2[i]] = i;
                pos3[p3[i]] = i;
                pos4[p4[i]] = i;
            }

            bool ok = true;

            for (int x = 0; x < n; x++) {

                int d1 = n + (pos2[x] - pos1[x]);
                int d2 = n + (pos3[x] - pos2[x]);
                int d3 = n + (pos4[x] - pos3[x]);

                if (d1 == d2 || d1 == d3 || d2 == d3) {
                    ok = false;
                    break;
                }
            }

            if (ok) break;
        }

        
        for (int x : p1) cout << x + 1 << ' ';
        for (int x : p2) cout << x + 1 << ' ';
        for (int x : p3) cout << x + 1 << ' ';
        for (int x : p4) cout << x + 1 << ' ';
        cout << '\n';
    }

    return 0;
}