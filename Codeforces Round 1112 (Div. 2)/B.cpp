#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int runs = n - k;

    // نحتاج على الأقل Runين حتى نستطيع موازنة 0 و 1
    if (runs == 1) {
        cout << -1 << '\n';
        return;
    }

    // نبني الـ runs بحيث تكون الأحجام متوازنة قدر الإمكان
    // ثم نتحقق من الشروط.
    for (int start = 0; start <= 1; start++) {
        for (int big = 0; big < runs; big++) {

            string s;

            for (int i = 0; i < runs; i++) {
                int len = (i == big ? k + 1 : 1);
                char c = ((i + start) % 2) + '0';

                s += string(len, c);
            }

            int zeros = count(s.begin(), s.end(), '0');
            int ones = n - zeros;

            int equalPairs = 0;

            for (int i = 0; i + 1 < n; i++) {
                if (s[i] == s[i + 1]) {
                    equalPairs++;
                }
            }

            if (abs(zeros - ones) <= 1 && equalPairs == k) {
                cout << s << '\n';
                return;
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}