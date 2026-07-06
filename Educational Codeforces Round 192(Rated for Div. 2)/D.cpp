#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();

  
    vector<int> Pa(n + 1, 0), Pb(m + 1, 0);
    for (int i = 0; i < n; i++) Pa[i + 1] = (Pa[i] + (a[i] - '0')) % 10;
    for (int j = 0; j < m; j++) Pb[j + 1] = (Pb[j] + (b[j] - '0')) % 10;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    dp[0][0] = 0;


    vector<vector<int>> row_max(10, vector<int>(m + 1, -1));

    vector<vector<int>> pref_max(10, vector<int>(m + 1, -1));


    int init_d = (Pa[0] - Pb[0] + 10) % 10;
    row_max[init_d][0] = 0;
    fill(pref_max[init_d].begin(), pref_max[init_d].end(), 0);

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {
            int d = (Pa[i] - Pb[j] + 10) % 10;
            int best_prev = pref_max[d][j - 1];
            if (best_prev != -1) {
                dp[i][j] = best_prev + 1;
            }
        }


        for (int j = 0; j <= m; j++) {
            if (dp[i][j] != -1) {
                int d = (Pa[i] - Pb[j] + 10) % 10;
                row_max[d][j] = max(row_max[d][j], dp[i][j]);
            }
        }


        for (int d = 0; d < 10; d++) {
            int current_max = -1;
            for (int j = 0; j <= m; j++) {
                current_max = max(current_max, row_max[d][j]);
                pref_max[d][j] = current_max;
            }
        }
    }

    cout << dp[n][m] << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}