// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string s, t;
//     cin >> s >> t;

//     int pos = s.find('|');

//     int left = pos;
//     int right = s.size() - pos - 1;

//     int remaining = t.size();

//     int diff = abs(left - right);

//     if (diff > remaining) {
//         cout << "Impossible\n";
//         return 0;
//     }

//     if ((remaining - diff) % 2 != 0) {
//         cout << "Impossible\n";
//         return 0;
//     }

//     int needLeft = 0;
//     int needRight = 0;

//     if (left < right) {
//         needLeft = diff;
//     } else {
//         needRight = diff;
//     }

//     int rest = remaining - diff;

//     needLeft += rest / 2;
//     needRight += rest / 2;

//     int index = 0;

//     string leftSide = s.substr(0, pos);
//     string rightSide = s.substr(pos + 1);

//     for (int i = 0; i < needLeft; i++) {
//         leftSide += t[index++];
//     }

//     for (int i = 0; i < needRight; i++) {
//         rightSide += t[index++];
//     }

//     cout << leftSide << "|" << rightSide << '\n';

//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s , t , left , right;
    cin>> s;
    int pos = s.find('|');
    left = s.substr(0 , pos);
    right = s.substr(pos + 1);
    cin>> t;
    for(auto letter : t){
        if(left.size() <= right.size()) left += letter;
        else right+= letter;
    }
    cout<< (left.size() == right.size() ? left + '|' + right : "Impossible")<<endl;
}