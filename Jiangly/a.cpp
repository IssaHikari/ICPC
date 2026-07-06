#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>> a[i];

    int min_value = 2e9;
    int best_t = 1;

    for(int t = 1; t <= 100; t++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            // a[i] < t - 1  sum += t-1 - a[i]
            if(a[i] < t - 1) sum += (t - 1) - a[i];
            else if(a[i] > t + 1) sum += a[i] - (t + 1);
        }
        if(sum < min_value){
            min_value = sum;
            best_t = t;
        }
    }

    cout<< best_t << " " << min_value << "\n";
    return 0;
}