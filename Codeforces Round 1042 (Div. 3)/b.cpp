#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>> n;
	if(n == 2){
		cout<< -1 << " " << 2 << endl;
		return;
	}
	for(int i =0; i< n; i++){
		if(i % 2 == 0)
			cout<< -1 <<" ";
		else 
			if(i != n -1)
				cout<< 3 <<" ";	
			else 
				cout<< 2 <<" ";
	}
	cout<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>> t;
	while(t--) solve();


	return 0;
}
