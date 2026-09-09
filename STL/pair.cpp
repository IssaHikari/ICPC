#include<bits/stdc++.h>

using namespace std;

int main(){

    pair<int, int> p = {1 , 2};
    cout<<p.first<<" "<<p.second<<"\n";

    vector<pair<int ,int>> v;
    v.push_back({1, 2});
    v.push_back({3, 4});
    cout<<v[0].first<<" "<<v[0].second<<"\n";


    auto t = make_pair(1 , 3);
    cout<<t.first<<" "<<t.second<<"\n";

    pair<string , int> p1 = {"Issa" , 20};

    cout<<p1.first;
    cout<<p1.second;
    cout<<"\n";
    vector<pair<int , int>> e;
    e.push_back({1 , 2});
    e.push_back({1 , 3});
    e.push_back({1 , 4});

    for(int i = 0; i < e.size(); i++){
        cout<<e[i].first<<" "<<e[i].second<<"\n";
    }


    auto ttt = make_pair(10 ,20);
    pair<int, int> tt = make_pair(10 , 20);
    cout<<ttt.first<<" "<<ttt.second<<"\n";
    cout<<tt.first<<" "<<tt.second<<"\n";




    for(auto x : e){
        cout<<x.first<<" "<<x.second<<"\n";
    }

    for(auto [x, y] : e){
        cout<<x<<" "<<y<<"\n";
    }
// auto auto&

    for(auto [x, y] : e){ //nathing change because we add in the copy
        x++;
    }
    for(auto [x, y] : e){
        cout<<x<<" "<<y<<"\n";
    }

    for(auto& [x , y] : e){ // this change the value of x because we access the reference of x
        x++;
    }

    for(auto [x , y] : e){
        cout<<x<<" "<<y<<"\n";
    }

    vector<pair<int , int>> v;

    v.push_back({1 , 10});
    v.push_back({2 , 20});
    v.push_back({3 , 30});
    v.push_back({4 , 40});
    v.push_back({5 , 50});

    for(auto [x,y] : v){
        cout<<x<<" "<<y<<"\n";
    }
    

    return 0;
}