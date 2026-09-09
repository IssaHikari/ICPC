#include<bits/stdc++.h>

using namespace std;

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    int n; cin >> n;
    set<int> a;
    vector<int> v;

    for(int i = 0;i < n; i++) {

        int x; cin >> x;
        a.insert(x);
    }

    for(auto i : a){

        v.push_back(i);
    }

    if(v.size() == 1){

        cout<< 0 << endl;
        return 0;
    }else if(v.size() == 2){

        if((v[1] - v[0]) % 2 == 0){

            cout << (v[1] - v[0]) / 2 << endl;
        }else {

            cout<< v[1] - v[0] << endl;
        }
    }else if(v.size() == 3){

        if((v[2] - v[1]) == (v[1] - v[0])){

            cout<< (v[1] - v[0]) << endl;
        }else {

            cout<< -1 << endl;
        }
    }else {
        
        cout<< -1 << endl;
    }
    return 0;
}