#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    vector<long long> lengths;
    int current_len = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            current_len++;
        } else {
            lengths.push_back(current_len);
            current_len = 1;
        }
    }
    lengths.push_back(current_len);


    sort(lengths.begin(), lengths.end());

    int m = lengths.size();
    

    vector<long long> suf_sum(m + 1, 0);
    for (int i = m - 1; i >= 0; i--) {
        suf_sum[i] = suf_sum[i + 1] + lengths[i];
    }

    long long ans = 0;


    for (int j = 0; j < m; j++) {
        if (j > 0 && lengths[j] == lengths[j - 1]) {
            continue; 
        }

        long long C = m - j;      
        long long V = suf_sum[j];  


        long long target = k - V;

        if (target % C == 0) {
            long long Sp = target / C;
            if (lengths[j] + Sp >= 1) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}