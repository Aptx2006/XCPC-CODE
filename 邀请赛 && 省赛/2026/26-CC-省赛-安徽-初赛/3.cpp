#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(A) A.begin(), A.end()
int n, m, q , k;

void solve(){
	cin >>n>>k;
	vector<int>a(n);
	for(int &i : a){
		cin >> i;
	}
	//for(int i=1;i<n;i++)a[i] += a[i-1];
	int ans = 0,cur = 0;
	for(int i=0;i<k;i++){
		cur+=a[i];
	}
	ans=max(ans,cur);
	for(int i=k;i<n;i++){
		
		cur+=a[i];
		cur-=a[i-k];
		ans=max(ans,cur);
	}
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}