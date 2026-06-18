#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    // ترتيب النقاط حسب X
    sort(points.begin(), points.end());

    int ans = 0;
    int maxY = 0;

    for (auto [x, y] : points) {
        if (y > maxY) {
            ans++;
            maxY = y;
        }
    }

    cout << ans << '\n';

    return 0;
}