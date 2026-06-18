#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<vector<ll>> a(N, vector<ll>(N));
        for (auto &row : a)
            for (auto &x : row)
                cin >> x;

        // dp[i][j] = minimal cost to guarantee win from (i,j)
        vector<vector<ll>> dp(N, vector<ll>(N, INF));

        // priority queue for Dijkstra
        priority_queue<
            tuple<ll,int,int>,
            vector<tuple<ll,int,int>>,
            greater<>
        > pq;

        // initial: take all cells as "white candidates"
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = a[i][j];
                pq.push({dp[i][j], i, j});
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            if (cost != dp[x][y]) continue;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                ll newCost = dp[x][y] + a[nx][ny];

                if (newCost < dp[nx][ny]) {
                    dp[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }
}