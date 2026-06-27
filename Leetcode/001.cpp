#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>> n;
    vector<int> tab(n);
    for(int i = 0; i<n;i++) cin>> tab[i];
    sort(tab.begin() , tab.end());
    for(int i = 0; i < n - 1; i++){
        if(tab[i] == tab[i + 1]){
            cout<< "true"<<endl;
            return 0;
        }
    } 

    cout<<"false"<<endl;
    return 0;

}