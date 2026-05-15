#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m, q;

void solve(){
	cin >> n >> q;
	vector<double> a(n), pre(n + 2);
	for(auto &x: a) cin >> x;
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i - 1];
	}
	while(q--) {
		int l, r;
		cin >> l >> r;
		double ans = pre[r] - pre[l - 1];	
		cout << fixed << setprecision(2) << ans << '\n';
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}