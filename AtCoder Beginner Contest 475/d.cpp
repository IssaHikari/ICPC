#include <bits/stdc++.h>
using namespace std;

vector<int> getPattern(string s) {
    map<char, int> mp;
    vector<int> pattern;
    int id = 0;

    for (char c : s) {
        if (!mp.count(c)) {
            mp[c] = id++;
        }

        pattern.push_back(mp[c]);
    }

    return pattern;
}

bool isPrime(int x) {
    if (x < 2) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    vector<int> pattern = getPattern(S);

    int k = 0;
    for (int x : pattern)
        k = max(k, x + 1);

    // digit assigned to each pattern number
    vector<int> digit(k, -1);

    function<bool(int)> dfs = [&](int pos) -> bool {
        if (pos == (int)S.size()) {
            int number = 0;

            for (int i = 0; i < (int)S.size(); i++) {
                number = number * 10 + digit[pattern[i]];
            }

            if (isPrime(number)) {
                cout << number << '\n';
                return true;
            }

            return false;
        }

        int id = pattern[pos];

        // Already assigned this pattern value
        if (digit[id] != -1)
            return dfs(pos + 1);

        for (int d = 0; d <= 9; d++) {

            // First digit cannot be zero
            if (pos == 0 && d == 0)
                continue;

            // Every different character/pattern value
            // must get a different digit
            bool used = false;

            for (int x : digit) {
                if (x == d) {
                    used = true;
                    break;
                }
            }

            if (used)
                continue;

            digit[id] = d;

            if (dfs(pos + 1))
                return true;

            digit[id] = -1;
        }

        return false;
    };

    if (!dfs(0))
        cout << -1 << '\n';

    return 0;
}
