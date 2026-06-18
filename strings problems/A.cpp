#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    size_t p1 = s.find('h');
    size_t p2 = (p1 != string::npos) ? s.find('e', p1 + 1) : string::npos;
    size_t p3 = (p2 != string::npos) ? s.find('l', p2 + 1) : string::npos;
    size_t p4 = (p3 != string::npos) ? s.find('l', p3 + 1) : string::npos;
    size_t p5 = (p4 != string::npos) ? s.find('o', p4 + 1) : string::npos;

    if (p5 != string::npos)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}