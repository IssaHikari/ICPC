#include <bits/stdc++.h>
using namespace std;

bool check(vector<pair<int,int>>& v, int x) {

    // Find a pair that does not contain x
    for (auto p : v) {

        if (p.first != x && p.second != x) {

            // y must be one of these two numbers
            int y1 = p.first;
            int y2 = p.second;

            // Try y1
            bool ok = true;

            for (auto q : v) {
                if (q.first != x && q.second != x &&
                    q.first != y1 && q.second != y1) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return true;

            // Try y2
            ok = true;

            for (auto q : v) {
                if (q.first != x && q.second != x &&
                    q.first != y2 && q.second != y2) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return true;

            return false;
        }
    }

    // Every pair contains x
    // We can choose any y different from x.
    return true;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> v(m);

    for (auto &p : v)
        cin >> p.first >> p.second;

    if (check(v, v[0].first) ||
        check(v, v[0].second))
        cout << "YES\n";
    else
        cout << "NO\n";
}
