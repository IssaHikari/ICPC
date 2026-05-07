#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int ans1 = 0 , ans2 =0;
    bool test = true;
    for(int i = N - 1; i >= 0; i--){
        if(test){
            ans1 += A[i];
            test = false;
        }else {
            ans2 += A[i];
            test = true;
        }
    }
    cout << ans1 - ans2 << endl;


    return 0;
}