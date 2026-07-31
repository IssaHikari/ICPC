#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n % 2 != 0 ) cout<< 0<<endl;
    else {
        long long r =pow(2 , (n / 2));
        cout<< r <<endl;
    } 
    return 0;
}