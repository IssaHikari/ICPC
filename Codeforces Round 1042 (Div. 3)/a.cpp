#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; 
	cin>> n;
	vector<int> a(n) , b(n);
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int j = 0; j < n; j++) cin>>b[j];
	int ans = 0;
	for(int i =0; i< n; i++){
		if(a[i] > b[i]) ans += a[i] - b[i];
	}
	cout<< ans + 1 <<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>> t;

	while(t--) solve();

	return 0;
}
