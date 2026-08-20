#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string A, B, C;
    cin >> A >> B >> C;

    vector<int> a, b, c;

    for (int i = 0; i < 2 * N; i++) {
        if (A[i] == '1') a.push_back(i);
        if (B[i] == '1') b.push_back(i);
        if (C[i] == '1') c.push_back(i);
    }

    string X(2 * N, '0');

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        int x = max(min(a[i], b[i]), min(max(a[i], b[i]), c[i]));

        X[x] = '1';

        ans += abs(a[i] - x);
        ans += abs(b[i] - x);
        ans += abs(c[i] - x);
    }

    cout << ans << '\n';
    cout << X << '\n';

    return 0;
}