#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    

    vector<tuple<int,int,int>> participants(n);
    
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        participants[i-1] = {i, a, b};
    }
    

    sort(participants.begin(), participants.end(), 
        [](const tuple<int,int,int>& x, const tuple<int,int,int>& y) {
            int ix = get<0>(x), ax = get<1>(x), bx = get<2>(x);
            int iy = get<0>(y), ay = get<1>(y), by = get<2>(y);
            
            if (bx != by) return bx > by;   
            if (ax != ay) return ax > ay;   
            return ix < iy;                
        }
    );
    
    for (auto& p : participants) {
        cout << get<0>(p) << "\n";
    }
    
    return 0;
}