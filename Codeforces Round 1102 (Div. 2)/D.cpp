#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s, z;
        cin >> s >> z;

        ll cnt1_s = 0, cnt0_s = 0;
        ll cnt1_z = 0, cnt0_z = 0;

        for (char c : s) {
            if (c == '1') cnt1_s++;
            else cnt0_s++;
        }

        for (char c : z) {
            if (c == '1') cnt1_z++;
            else cnt0_z++;
        }

        ll cross = cnt1_s * cnt0_z + cnt0_s * cnt1_z;

        ll power = 1LL << (k - 1);

        cout << cross * power << "\n";
    }

    return 0;
}