#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n , m , a;
    cin>> n >> m >> a;
    long long l = n / a;
    if(n % a != 0) l++;
    long long r = m / a;
    if(m % a != 0) r++;
    cout<< l*r<<endl;
    return 0;
}