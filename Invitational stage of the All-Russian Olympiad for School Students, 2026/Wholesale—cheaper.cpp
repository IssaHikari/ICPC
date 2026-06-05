#include<bits/stdc++.h>

using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n , m , r , k , p , s;
    cin >> n;
    cin >> m;
    cin >> r;
    cin >> k;
    cin >> p;
    cin >> s;
    ll sum = n + m;
    ll nbr_packs = s / p;
    ll deff = s - nbr_packs * p;
    ll rest = deff / r;
    ll ans = nbr_packs * k + rest;
    if(ans >= sum){
        cout << ans << endl;
    }else {
        cout << -1 << endl;
    }
    return 0;
}