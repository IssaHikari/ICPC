#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    long long L;

    cin >> N >> S >> L;

    vector<long long> A(N - 1);

    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }

    
    vector<long long> prefix(N);

    for (int i = 1; i < N; i++) {
        prefix[i] = prefix[i - 1] + A[i - 1];
    }
    int s = S - 1;
    int answer = 1;
    for (int left = 0; left <= s; left++) {
        for (int right = s; right < N; right++) {
            long long leftDist = prefix[s] - prefix[left];
            long long rightDist = prefix[right] - prefix[s];
            long long cost = min(
                2 * leftDist + rightDist,
                leftDist + 2 * rightDist
            );

            if (cost <= L) {
                answer = max(answer, right - left + 1);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
