#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>> n;
    vector<long long> L(n);
    long long sum = 0;
    for(int i= 0; i<n;i++){
        cin>>L[i];
        sum += L[i];
    }

    long long sum_left = 0 , mn = LLONG_MAX;
    for(int r = 0 ; r < n ; r++){//r = 1
        sum_left += L[r]; // sum_left = 7
        int diff = abs((sum - sum_left) - sum_left); 
        if(diff < mn) mn = diff; 
    }
    cout<<mn<<endl;
    return 0;
}