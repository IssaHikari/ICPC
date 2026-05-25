#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n , m;
    cin>> n >> m;

    long long x , y;
    cin>> x >> y;

    long long k;
    cin>> k;

    long long ans = 0;
    
    for (long long i = 0; i < k ; i++){
        long long dx , dy;
        cin>> dx>> dy;

        long long Total = LLONG_MAX;

        if(dx > 0){
            Total = min(Total , (n - x) / dx);
        }else if(dx < 0){
            Total = min(Total , (x - 1) / (-dx));
        }
        if(dy > 0){
            Total = min(Total , (m - y) / dy);
        }else if(dy < 0){
            Total = min(Total , (y - 1) / (-dy));
        }

        ans += Total;
        x += Total * dx;
        y += Total * dy;
    }
    cout<< ans << endl;

    return 0;
}