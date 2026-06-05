#include<bits/stdc++.h>

using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    if(n % 2 == 0) {
        ll m = n / 2;
        cout << ((m - 1)*(m - 1)) << endl;
        cout << (m * m) << endl;   
    }else {
        ll m = (n + 1) / 2;
        cout << ((m - 1) * (m - 1)) << endl; 
        cout << ((m - 1) * (m - 1)) << endl; 
    }
    return 0;
}