#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n , m;
    cin>> n >> m;
    vector<long long> v(n);
    for(int i =0 ;i <n;i++){
        cin>> v[i];
    }

    priority_queue<long long> pq;
    long long sum = 0;
    long long ans = LLONG_MIN;

    for(int i =0; i< n; i++){
        if((int)pq.size() == m - 1){
            ans = max(ans , 1LL * m * v[i] - sum);
        }

        pq.push(v[i]);
        sum += v[i];

        if((int)pq.size() > m - 1){
            sum -= pq.top();
            pq.pop();
        }
    }
    cout<< ans << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin>> t;

    while(t--) 
        solve();

    return 0;
}