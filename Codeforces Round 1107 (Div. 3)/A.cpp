#include<bits/stdc++.h>

void solve(){
    int x , y;
    std::cin>> x >> y;
    if(x % y == 0) std::cout<<"YES"<<"\n";
    else std::cout<<"NO"<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t; 
    std::cin>> t;
    while(t--) solve();
    return 0;
}