// #include<bits/stdc++.h>

// using namespace std;
// void solve(){
//     int n;
//     cin>> n;
//     vector<int> a(n);
//     for(int i = 0; i< n; i++) cin>> a[i];
//     int nbr_1 = 0 , nbr_2 = 0, nbr_3 = 0 , nbr_12 = 0;
//     bool test_1 = false , test_2 = false , test_3 = false;
//     for(int i =0; i<n; i++ ){
//         if(a[i] == 1) nbr_1++;
//         else if(a[i] == 2) nbr_2++;
//         else if(a[i] == 3) nbr_3++;

//         if(nbr_1>= nbr_2 + nbr_3 && i < n - 1 && test_1 == false){
//             test_1 = true;
//             nbr_1 = 0;
//             nbr_2 = 0;
//             nbr_3 = 0;
//         }else if(test_2 == false && test_1 == true && i < n-1){
//             if(a[i] == 1 || a[i] == 2){
//                 nbr_12++;
//             }else {
//                 nbr_3++;
//             }
//             if(nbr_12 >= nbr_3 && i < n - 1){
//                 test_2 = true;
//                 break;
//             }
//         }
//     }
//     if(test_1 == true && test_2 == true) cout<<"YES"<<"\n";
//     else cout<< "NO"<<"\n";
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>> t;
//     while(t--) solve();
// }

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    vector<int> p1(n), p2(n);
    int c1 = 0, c2 = 0, c3 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) c1++;
        else if (a[i] == 2) c2++;
        else if (a[i] == 3) c3++;
        
        p1[i] = c1 - (c2 + c3);
        p2[i] = (c1 + c2) - c3;
    }


    vector<int> max_p2(n);
    max_p2[n - 2] = p2[n - 2];
    for (int i = n - 3; i >= 0; i--) {
        max_p2[i] = max(p2[i], max_p2[i + 1]);
    }

    bool possible = false;
    

    for (int L = 0; L <= n - 3; L++) {
        if (p1[L] >= 0) { 
            if (max_p2[L + 1] >= p2[L]) {
                possible = true;
                break;
            }
        }
    }

    if (possible) cout << "YES\n";
    else cout << "NO\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}