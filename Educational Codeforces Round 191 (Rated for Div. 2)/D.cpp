#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);

        unordered_map<ll, vector<int>> pos;
        pos.reserve(n * 2);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }

        unordered_map<ll, int> badVal;
        badVal.reserve(pos.size() * 2);

        int badCnt = 0;

        for (auto &it : pos) {
            auto &v = it.second;
            int cnt = (int)v.size();
            bool bad = (v.back() - v.front() + 1 != cnt);
            badVal[it.first] = bad;
            badCnt += bad;
        }

        if (badCnt == 0) {
            cout << "YES\n";
            continue;
        }

        vector<array<int, 3>> runs;
        for (int i = 1, j; i <= n; i = j + 1) {
            j = i;
            while (j + 1 <= n && a[j + 1] == a[i]) j++;
            runs.push_back({i, j, 0});
        }

        unordered_map<ll, int> runCnt;
        runCnt.reserve(pos.size() * 2);

        int excess = 0;
        int ptr = 0;

        for (int i = 1, j; i <= n; i = j + 1) {
            j = i;
            while (j + 1 <= n && a[j + 1] == a[i]) j++;
            runCnt[a[i]]++;
        }

        vector<int> cand;
        for (int i = 1, j; i <= n; i = j + 1) {
            j = i;
            while (j + 1 <= n && a[j + 1] == a[i]) j++;

            if (runCnt[a[i]] > 1) {
                for (int x : {i - 1, i, i + 1, j - 1, j, j + 1}) {
                    if (1 <= x && x <= n) cand.push_back(x);
                }
            }
        }

        for (auto &it : runCnt) excess += max(0, it.second - 1);

        if (excess > 4) {
            cout << "NO\n";
            continue;
        }

        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());

        auto newBad = [&](ll val, int rem, int add) -> int {
            auto &v = pos[val];
            int m = (int)v.size();

            int mn, mx;

            if (m == 1) {
                mn = mx = add;
            } else {
                int first = v.front();
                int last = v.back();

                int secondFirst = (m >= 2 ? v[1] : first);
                int secondLast = (m >= 2 ? v[m - 2] : last);

                mn = (rem == first ? secondFirst : first);
                mx = (rem == last ? secondLast : last);

                mn = min(mn, add);
                mx = max(mx, add);
            }

            return (mx - mn + 1 != m);
        };

        auto checkSwap = [&](int i, int j) -> bool {
            if (i == j) return false;

            ll x = a[i];
            ll y = a[j];

            if (x == y) {
                return badCnt == 0;
            }

            int cur = badCnt;

            cur -= badVal[x];
            cur -= badVal[y];

            cur += newBad(x, i, j);
            cur += newBad(y, j, i);

            return cur == 0;
        };

        bool ok = false;

        for (int i = 0; i < (int)cand.size() && !ok; i++) {
            for (int j = i + 1; j < (int)cand.size() && !ok; j++) {
                if (checkSwap(cand[i], cand[j])) {
                    ok = true;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}