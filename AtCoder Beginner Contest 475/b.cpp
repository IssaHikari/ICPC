#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long n_100 = 0, n_10 = 0, n_1 = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        long long m = ((x + 999) / 1000) * 1000;

        long long d = m - x;

        long long div = d / 100;
        n_100 += div;

        long long rs = d % 100;

        div = rs / 10;
        n_10 += div;

        rs = rs % 10;
        n_1 += rs;
    }

    cout << n_1 << " " << n_10 << " " << n_100 << endl;

    return 0;
}
