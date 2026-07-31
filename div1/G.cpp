#include <iostream>

using namespace std;

void solve()
{

    long long n;
    if (!(cin >> n))
    {
        return;
    }

    cout << (n + 1) / 10 << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t))
    {
        return 0;
    }

    while (t--)
    {
        solve();
    }

    return 0;
}
