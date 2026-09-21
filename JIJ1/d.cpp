#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K, X, Y;

    cin >> N >> M >> K;
    cin >> X >> Y;

    vector<ll> A(N), B(M);

    for (ll &x : A)
        cin >> x;

    for (ll &x : B)
        cin >> x;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<ll> prefA(N + 1, 0);

    for (int i = 0; i < N; i++) {
        prefA[i + 1] = prefA[i] + A[i];
    }

    vector<ll> prefB(M + 1, 0);
    vector<ll> prefK(M + 1, 0);

    for (int i = 0; i < M; i++) {
        prefB[i + 1] = prefB[i] + B[i];

        ll needK = (B[i] + K - 1) / K;

        prefK[i + 1] = prefK[i] + needK;
    }

    ll total = X + Y * K;

    int answer = 0;

    for (int d = 0; d <= M; d++) {

        if (prefK[d] > Y)
            break;

        ll remaining = total - prefB[d];

        int q = upper_bound(
            prefA.begin(),
            prefA.end(),
            remaining
        ) - prefA.begin() - 1;

        answer = max(answer, d + q);
    }

    cout << answer << '\n';

    return 0;
}