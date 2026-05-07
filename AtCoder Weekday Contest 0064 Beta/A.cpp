#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int group_count = 0;
    bool in_group = false;

    for (int i = 0; i < N; i++) {
        if (A[i] >= K) {
            if (!in_group) {
                group_count++;
                in_group = true; 
            }
        } else {
            
            in_group = false;
        }
    }

    cout << group_count << endl;

    return 0;
}