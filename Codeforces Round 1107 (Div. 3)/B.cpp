#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


vector<long long> good_numbers;


void dfs_generate(long long current_num, int d1, int d2) {
    if (current_num > 1000000000LL) return; 
    
    if (current_num >= 2) {
        good_numbers.push_back(current_num);
    }
    
    
    if (current_num * 10 + d1 > current_num) dfs_generate(current_num * 10 + d1, d1, d2);
    if (d1 != d2 && current_num * 10 + d2 > current_num) dfs_generate(current_num * 10 + d2, d1, d2);
}


bool is_good(long long n) {
    int mask = 0; 
    while (n > 0) {
        int digit = n % 10;
        mask |= (1 << digit);
        n /= 10;
    }
    
    return __builtin_popcount(mask) <= 2;
}

void precompute() {
    
    for (int i = 0; i <= 9; i++) {
        for (int j = i; j <= 9; j++) {
            
            if (i != 0) dfs_generate(i, i, j);
            if (j != 0 && i != j) dfs_generate(j, i, j);
        }
    }
    
    sort(good_numbers.begin(), good_numbers.end());
    good_numbers.erase(unique(good_numbers.begin(), good_numbers.end()), good_numbers.end());
}

void solve() {
    long long x;
    cin >> x;
    
    
    for (long long y : good_numbers) {
        long long product = x * y;
        if (is_good(product)) {
            cout << y << "\n";
            return;
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}