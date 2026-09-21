#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int zeros = 0;

        for (char c : s) {
            if (c == '0')
                zeros++;
        }

        int ones = n - zeros;

        int bad = n / 2 - k;

        if (zeros >= bad &&
            ones >= bad &&
            (zeros - bad) % 2 == 0 &&
            (ones - bad) % 2 == 0) {

            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
