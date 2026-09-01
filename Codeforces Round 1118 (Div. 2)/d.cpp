#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Returns true if n is prime
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Returns true if n is a prime power (p^k for prime p and k >= 1)
bool is_prime_power(int n) {
    if (n < 2) return false;
    int p = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            p = i;
            break;
        }
    }
    if (p == 0) p = n; // n itself is prime
    
    int temp = n;
    while (temp % p == 0) temp /= p;
    return temp == 1;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Precompute prime powers up to 50
    vector<int> prime_powers;
    for (int i = 2; i <= 50; ++i) {
        if (is_prime_power(i)) {
            prime_powers.push_back(i);
        }
    }

    vector<int> ans;

    for (int x : prime_powers) {
        // Collect all required prime powers strictly less than x
        vector<int> req;
        for (int y : prime_powers) {
            if (y < x) req.push_back(y);
        }

        bool possible = false;
        int l = 0;

        // Process contiguous segments that contain NO multiples of x
        while (l < n) {
            if (a[l] % x == 0) {
                l++;
                continue;
            }

            int r = l;
            while (r < n && a[r] % x != 0) {
                r++;
            }

            // Subarray [l, r-1] has no multiples of x.
            // Check if there exists any subarray in [l, r-1] that contains all prime powers y < x as divisors.
            int m = req.size();
            vector<int> count(m, 0);
            int covered_count = 0;
            int right = l;

            for (int left = l; left < r; ++left) {
                while (right < r && covered_count < m) {
                    for (int i = 0; i < m; ++i) {
                        if (a[right] % req[i] == 0) {
                            if (count[i] == 0) covered_count++;
                            count[i]++;
                        }
                    }
                    right++;
                }

                if (covered_count == m) {
                    possible = true;
                    break;
                }

                // Move left pointer forward
                for (int i = 0; i < m; ++i) {
                    if (a[left] % req[i] == 0) {
                        count[i]--;
                        if (count[i] == 0) covered_count--;
                    }
                }
            }

            if (possible) break;
            l = r;
        }

        if (possible) {
            ans.push_back(x);
        }
    }

    // Output results
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << (i == (int)ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}