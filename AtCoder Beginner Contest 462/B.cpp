#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> received(N + 1);

    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;

        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;

            // الشخص i أرسل هدية إلى x
            // إذن x استلم هدية من i
            received[x].push_back(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << received[i].size();

        for (int person : received[i]) {
            cout << ' ' << person;
        }

        cout << '\n';
    }

    return 0;
}