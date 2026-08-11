#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<long long> a(n), b(m);
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int i = 0;
  bool possible = true;

  for (int j = 0; j < m; j++) {
    if (i >= n) {
      possible = false;
      break;
    }

    if (a[i] > b[j]) {
      possible = false;
      break;
    }

    long long lastConsumed = a[i];
    while (i < n && a[i] <= b[j]) {
      lastConsumed = a[i];
      i++;
    }

    if (i < n && a[i] >= b[j]) {
      i++;
    } else {

      possible = false;
      break;
    }
  }

  if (i != n)
    possible = false;

  cout << (possible ? "YES" : "NO") << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
