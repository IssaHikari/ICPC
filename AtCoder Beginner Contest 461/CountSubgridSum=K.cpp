#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, K;
    cin >> H >> W >> K;

    vector<string> grid(H);
    for (int i = 0; i < H; i++)
        cin >> grid[i];


    vector<vector<int>> col(H + 1, vector<int>(W, 0));

    for (int i = 1; i <= H; i++) {
        for (int j = 0; j < W; j++) {
            col[i][j] = col[i - 1][j] + (grid[i - 1][j] - '0');
        }
    }

    long long ans = 0;

   
    vector<int> freq(H * W + 1);
    vector<int> used;

    for (int r1 = 1; r1 <= H; r1++) {
        for (int r2 = r1; r2 <= H; r2++) {

         
            for (int x : used)
                freq[x] = 0;
            used.clear();

            freq[0] = 1;
            used.push_back(0);

            int prefSum = 0;

            for (int c = 0; c < W; c++) {
               
                prefSum += col[r2][c] - col[r1 - 1][c];

                if (prefSum >= K)
                    ans += freq[prefSum - K];

                if (freq[prefSum] == 0)
                    used.push_back(prefSum);

                freq[prefSum]++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}