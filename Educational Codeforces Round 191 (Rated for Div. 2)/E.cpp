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

        int k = __lg(n) + 1;
        vector<string> s(k);

        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }

        vector<int> p(k);
        iota(p.begin(), p.end(), 0);

        long long ans = 0;

        do {
            vector<int> val(n, 0);

            for (int i = 0; i < k; i++) {
                int bit = p[i];
                for (int j = 0; j < n; j++) {
                    if (s[i][j] == '1') {
                        val[j] |= (1 << bit);
                    }
                }
            }

            vector<int> freq(n + 1, 0);
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (val[i] < 1 || val[i] > n) {
                    ok = false;
                    break;
                }
                freq[val[i]]++;
                if (freq[val[i]] > 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans++;

        } while (next_permutation(p.begin(), p.end()));

        cout << ans << "\n";
    }

    return 0;
}