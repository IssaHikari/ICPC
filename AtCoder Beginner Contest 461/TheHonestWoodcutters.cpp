#include<bits/stdc++.h>

using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<int> A(N + 1);
    vector<int> B(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    bool check = false;
    for (int i = 1; i <= N; i++) {
        if (B[A[i]] == i){
            continue;
        }else {
            check = true;
            break;
        }
    }
    if(check){
        cout << "No";
    }else {
        cout << "Yes";
    }
    return 0;
}