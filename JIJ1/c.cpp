#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long f = 0 , s = 0 , t = 0;

    for (int i = 0; i < n; i++) {
        long long x = a[i];

        if(a[i] > f){
            t = s;
            s = f;
            f = x;
        }else if(a[i] > s){
            t = s;
            s = x;
        }else if(a[i] > t){
            t = x;
        }
        if(i >= 2){
            cout<< t << endl;
        }
    }

    return 0;
}