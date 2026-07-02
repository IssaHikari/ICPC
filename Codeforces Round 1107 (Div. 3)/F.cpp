#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int first_one = -1;
    int last_zero = -1;

    // Find the first '1'
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            first_one = i;
            break;
        }
    }

    // Find the last '0'
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            last_zero = i;
            break;
        }
    }

  
    if (first_one == -1 || last_zero == -1 || first_one > last_zero) {
        cout << "Bob\n";
        return;
    }

    bool all_even = true;
    int current_count = 0;
    char current_char = s[first_one];

    
    for (int i = first_one; i <= last_zero; i++) {
        if (s[i] == current_char) {
            current_count++;
        } else {
            if (current_count % 2 != 0) {
                all_even = false;
                break;
            }
            current_char = s[i];
            current_count = 1;
        }
    }
    
    
    if (current_count % 2 != 0) {
        all_even = false;
    }

    
    if (all_even) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}