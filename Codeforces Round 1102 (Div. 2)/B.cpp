#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll r = n % 12;
        ll a;

        if (r <= 9)
            a = r;
        else if (r == 10)
            a = 22;
        else
            a = 11;

        ll b = n - a;

        if (b < 0)
            cout << -1 << '\n';
        else
            cout << a << ' ' << b << '\n';
    }

    return 0;
}