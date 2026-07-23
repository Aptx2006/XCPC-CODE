#include<bits/stdc++.h>
using namespace std;

int n;

void solve(){
	cin>>n;
	vector<int> a(n + 1), b(n + 1), mp(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		mp[b[i]] = i;
	}
	vector<int> lis;
	for(int i = 1; i <= n; i++){
		auto x = lower_bound(lis.begin(), lis.end(), mp[a[i]]);
		if(x == lis.end())  lis.push_back(mp[a[i]]);
		else *x = mp[a[i]];
	}
	int lcs = lis.size();
	if(lcs == 1 or lcs == n){
		cout << "-1\n";
		return;
	}
	vector<int> ans(n + 1);
	for(int i = 1; i <= lcs; i++) {
		ans[i] = a[i + n - lcs];
	}
	for(int i = lcs + 1; i <= n; i++){
		ans[i] = a[n - i + 1];
	}
	if(ans == b){
		swap(ans[lcs + 1], ans[lcs]);
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
