#include<bits/stdc++.h>

using namespace std;

int main(){
    long long S ,P ,R;
    cin>> S >> P >> R;
    long long M;
    cin>> M;
    vector<pair<long long,long long>> v(M);
    for(int i = 0 ; i < M ; i++){
        cin>> v[i].first >> v[i].second;
        if(v[i].first == 1){
            S += v[i].second;
        }else {
            S -= v[i].second * P;
        }
    }
    cout<< S - R <<endl;
    return 0;
}