#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>> n;
	vector<long long> a(n);
	
	for(int i =0; i<n ;i++){
	    cin>> a[i];
	}
	
	sort(a.begin() , a.end());
	
	double center = (a[n - 1] + a[0]) / 2.0;
	
	for(int i = 0; i< n; i++){
	    if(a[i] == center){
	        cout<< center <<endl;
	        return 0;
	    }else if(a[i] > center){
	       double mn = abs(center - a[i - 1]);
	       double mx = abs(center - a[i]);
	       if(mn <= mx) cout<< a[i - 1];
	       else cout<< a[i];
	       return 0;
	    }
	}
	return 0;

}