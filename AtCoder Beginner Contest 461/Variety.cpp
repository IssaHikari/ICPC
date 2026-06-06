#include<bits/stdc++.h>

using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N , K , M;
    cin >> N >> K >> M;

    map<ll , vector<ll>> colorGroups;
    for(int i = 0; i < N; i++) {
        ll c , v;
        cin >> c >> v;
        colorGroups[c].push_back(v);
    }

    vector<ll> representatives; 
    vector<ll> remaining; 

    for (auto& [color , values] : colorGroups) {
        sort(values.begin() , values.end() , greater<ll>());
        representatives.push_back(values[0]);
        for (int i = 1; i < values.size(); i++) {
            remaining.push_back(values[i]);
        }
    }

     sort(representatives.begin(), representatives.end(), greater<int>());

    long long total = 0;

    
    for (int i = 0; i < M; i++) {
        total += representatives[i];
    }

    for (int i = M; i < representatives.size(); i++) {
        remaining.push_back(representatives[i]);
    }


    sort(remaining.begin(), remaining.end(), greater<int>());


    for (int i = 0; i < K - M; i++) {
        total += remaining[i];
    }

    cout << total << endl;

    return 0;
}