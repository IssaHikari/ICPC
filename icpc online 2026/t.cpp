#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin>> n >> m;
	vector<string> s(n);

	for(int i =0; i<n; i++){
		cin>> s[i];
	}

	sort(s.begin() , s.end());

	vector<bool> visit( n ,false);

	for(int i =0 ;i<m;i++){
		string t;
		cin>> t;
		auto it = lower_bound(s.begin() , s.end() , t);
		if(it != s.end() && *it == t){
			int j = it - s.begin();
			if(!visit[j]){
				cout<< "OK" << endl;
				visit[j] = true;
			}else{
				cout<< "REPEAT" << endl;
			}
		}else {
			cout<< "WRONG" <<endl;
		}
	}

	return 0;
}
