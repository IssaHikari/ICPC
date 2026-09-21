#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;

    if (A == 0) {
        if (B == 0) {
            if (C == 0)
                cout << -1 << '\n';
            else
                cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
            double x = -(double)C / B;
            cout << fixed << setprecision(10) << x << '\n';
        }

        return 0;
    }

    long long delta = 1LL * B * B - 4LL * A * C;

    if (delta < 0) {
        cout << 0 << '\n';
    }
    else if (delta == 0) {
        cout << 1 << '\n';

        double x = -(double)B / (2.0 * A);

        cout << fixed << setprecision(10) << x << '\n';
    }
    else {
        cout << 2 << '\n';

        double x1 = (-B - sqrt((double)delta)) / (2.0 * A);
        double x2 = (-B + sqrt((double)delta)) / (2.0 * A);

        if (x1 > x2)
            swap(x1, x2);

        cout << fixed << setprecision(10);
        cout << x1 << '\n';
        cout << x2 << '\n';
    }

    return 0;
}