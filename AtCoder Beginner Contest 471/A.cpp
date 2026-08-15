#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a , b;
    cin>>a >>b;
    int add = a +b;
    int sub = a - b;
    int mult = a * b;
    double div =(double)a / b;
    if(add == 9 || sub == 9 || mult == 9 || div == 9) cout<<"Nine\n";
    else cout<<"Nein\n";
    return 0;
}