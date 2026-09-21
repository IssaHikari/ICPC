#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;

    while (true) {
        a++;
        if (a > n)
            a = 1;

        b--;
        if (b < 1)
            b = n;

        if (a == b) {
            cout << "YES\n";
            break;
        }

        if (a == x || b == y) {
            cout << "NO\n";
            break;
        }
    }

    return 0;
}
