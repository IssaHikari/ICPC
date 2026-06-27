#include <iostream>

using namespace std;


const long long MOD = 998244353;
const long long MOD_EXP = MOD - 1; 
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    long long n, m, r, c;
    cin >> n >> m >> r >> c;


    // نستخدم باقي القسمة على MOD_EXP لتجنب أي طفحان (Overflow) لأن الأرقام قد تصل لمليار
    long long part1 = ((n - r + 1) % MOD_EXP) * ((c - 1) % MOD_EXP) % MOD_EXP;
    long long part2 = (m % MOD_EXP) * ((r - 1) % MOD_EXP) % MOD_EXP;
    
    long long E = (part1 + part2) % MOD_EXP;

  
    cout << power(2, E) << "\n";
}

int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}