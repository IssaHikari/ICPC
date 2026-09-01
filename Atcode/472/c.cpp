#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;

    cin >> N >> M >> K;

    vector<ll> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    queue<pair<int, ll>> q;
    ll sum = 0;

    for (int i = 0; i < N; i++) {

        // Remove snacks that are outside the last M days
        while (!q.empty() && q.front().first <= i - M) {
            sum -= q.front().second;
            q.pop();
        }

        // Try to eat today's snack
        if (sum + A[i] <= K) {
            cout << "Yes\n";

            sum += A[i];
            q.push({i, A[i]});
        } 
        else {
            cout << "No\n";
        }
    }

    return 0;
}