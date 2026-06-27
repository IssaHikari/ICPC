#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    long long S = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        S ^= a[i];
    }

   
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    long long winning_moves = 0;

    
    if (S == 0) {
        winning_moves = 1;
    } 
   
    else {
        for (int i = 0; i < n; i++) {
            if ((S ^ a[i]) < a[i]) {
                winning_moves++;
            }
        }
    }

  
    cout << winning_moves % 998244353 << "\n";
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