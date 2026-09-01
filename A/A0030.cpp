#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string  , string> data = {
        {"purple", "Power"},
        {"green" , "Time" },
        {"blue" , "Space" },
        {"orange" , "Soul"},
        {"red" , "Reality"},
        {"yellow" , "Mind"}
    };
    unordered_set<string> enterd;
    string key;
    int n;
    cin>> n;
    for(int i = 0 ; i < n; i++){
        cin>>key;
        enterd.insert(key);
    }
    cout<< 6 - enterd.size()<<endl;
    for(auto &[key , value] : data){
        if(!enterd.count(key)){
            cout<< value <<endl;
        }
    }

    return 0;
}