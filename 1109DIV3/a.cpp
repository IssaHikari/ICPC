#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int max_len = 0;
    int current_len = 0;
    
   
    for (char c : s) {
        if (c == '#') {
            current_len++;
        } else {
            max_len = max(max_len, current_len);
            current_len = 0; 
        }
    }
    
  
    max_len = max(max_len, current_len);
    
 
    int ans = (max_len + 1) / 2;
    cout << ans << "\n";
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