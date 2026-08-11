#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << n << '\n';

    return 0;
}