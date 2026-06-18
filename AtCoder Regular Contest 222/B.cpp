#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int64 a, b, c;
        cin >> a >> b >> c;

        int64 ans;

        if (b == 0) {
            // يوجد فقط حجر وورقة
            if (c >= a)
                ans = (a == 0 ? 0 : a - 1);
            else
                ans = c;
        }
        else if (c == 0) {
            // يوجد فقط حجر ومقص
            if (a >= b)
                ans = (b == 0 ? 0 : b - 1);
            else
                ans = a;
        }
        else if (a == 0) {
            // يوجد فقط مقص وورقة
            if (b >= c)
                ans = (c == 0 ? 0 : c - 1);
            else
                ans = b;
        }
        else {
            // الأنواع الثلاثة موجودة
            int64 sum = a + b + c;
            int64 mx = max({a, b, c});
            int64 others = sum - mx;

            if (mx > others)
                ans = others - 1;
            else
                ans = others;
        }

        cout << max<int64>(0, ans) << '\n';
    }

    return 0;
}