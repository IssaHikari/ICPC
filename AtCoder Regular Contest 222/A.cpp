#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        int K = 1;

        for (int i = 0; i < M; i++) {
            int L, R;
            cin >> L >> R;
            K = max(K, R - L + 1);
        }

        for (int i = 0; i < N; i++) {
            cout << (i % K) + 1;
            if (i + 1 < N) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}