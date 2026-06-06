#include<bits/stdc++.h>

using namespace std;

#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a > b) {
            if((a % 2 == 1 && b % 2 == 0) || (a % 2 == 0 && b % 2 == 1)) {                
                cout << 2 << endl;
            }else {
                cout << 1 << endl;
            }
        }else if(a < b) {
            if ((a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 2 == 1)) {
                cout << 2 << endl;

            }else {
                cout << 1 << endl;
            }
        }else {
            cout << 0 << endl;
        }


    }
    return 0;
}