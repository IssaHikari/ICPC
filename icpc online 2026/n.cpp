#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin>> n;

	vector<tuple< int , int , int>> v;
	for(int i =0; i < n; i++){
		int r , y , b;
		cin>> r >> y >> b;
		v.push_back({r , y , b});
	}

	int ans = 0;
	int l = 0;
	int sr = 0 , sy = 0 , sb = 0;
	for(int r = 0; r<n ; r++){
		sr += get<0>(v[r]);
		sy += get<1>(v[r]);
		sb += get<2>(v[r]);
		
		if(sr >= sy  && sr >= sb){
			ans++;
		}else {
			sr = get<0>(v[r]);
			sy = get<1>(v[r]);
			sb = get<2>(v[r]);
		}
	}

	return 0;
}
