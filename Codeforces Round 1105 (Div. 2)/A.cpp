#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    
    long long total_popcount = 0;
    long long current_bit_cost = 1;
    
   
    while (n >= current_bit_cost) {
       
        long long bits_to_buy = min(k, n / current_bit_cost);
        
       
        total_popcount += bits_to_buy;
        
       
        n -= bits_to_buy * current_bit_cost;
        
        
        current_bit_cost *= 2;
    }
    
    cout << total_popcount << "\n";
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