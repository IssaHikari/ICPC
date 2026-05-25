#include <bits/stdc++.h>
using namespace std;

bool isNonDegenerate(long long a, long long b, long long c) {
    return (a + b > c) &&
           (a + c > b) &&
           (b + c > a);
}

int main() {
    int n;
    cin >> n;
    vector<int> sides(n);
    for (int i = 0; i < n; i++) {
        cin >> sides[i];
    }
    

    return 0;
}