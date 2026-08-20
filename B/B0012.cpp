#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> buildPrefix(const vector<ll>& v) {
    vector<ll> prefix(v.size() + 1, 0);

    for (int i = 0; i < v.size(); i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    return prefix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n;

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    auto prefix_no_sort = buildPrefix(v);

    sort(v.begin(), v.end());

    auto prefix_sort = buildPrefix(v);

    cin >> m;

    for (int i = 0; i < m; i++) {
        ll type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            cout << prefix_no_sort[r] - prefix_no_sort[l - 1] << '\n';
        }
        else {
            cout << prefix_sort[r] - prefix_sort[l - 1] << '\n';
        }
    }

    return 0;
}