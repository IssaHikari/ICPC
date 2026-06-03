#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, t;
    cin >> n >> t;
    vector<long long> a(n-1);
    for (long long i = 0; i < n-1; i++){
        cin >> a[i];
    }
    
    long long count = 1;
    while(count <= n-1){
        long long tt = count + a[count - 1];
        if (tt == t){
            cout << "YES" << endl;
            break;
        } else if (tt > t){
            cout << "NO" << endl;
            break;
        } else {
            count = tt;  
        }
    }
    
    return 0;
}