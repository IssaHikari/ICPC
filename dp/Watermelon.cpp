#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>> n;
    if(n > 2)
    cout<< (n % 2 == 0 ? "YES\n" : "NO\n");
    else cout<<"NO\n";
    return 0;
}