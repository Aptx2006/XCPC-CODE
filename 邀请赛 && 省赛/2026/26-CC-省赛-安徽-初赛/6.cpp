#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(A) A.begin(), A.end()
int N, G, W;

struct nod{
	int w, v, c;
};

void solve(){
	cin >> N >> G >> W;
	vector< vector<nod> > A(G + 1);
	for(int i = 0; i < N; i++) {
		int g, w, v, c;
		cin >> g >> w >> v >> c;
		A[g].push_back({w, v, c});
	}
	vector<int> dp(W + 5);
	for(int i = 1; i <= G; i++) {
		if(A[i].empty()) continue;
		auto ndp = dp;
		for(auto &[w, v, c]: A[i]) {
			auto xdp = dp;
			for(int k = 1; c > 0; k <<= 1) {
				int use = min(k, c);
				c -= use;
				int ww = use * w;
				int vv = use * v;
				for(int j = W; j >= ww; j--) {
					xdp[j] = max(xdp[j], xdp[j - ww] + vv);
				}
			}
			for(int j = 0; j <= W; j++) {
				ndp[j] = max(ndp[j], xdp[j]);
			}
		}
		dp = move(ndp);
	}
	cout << dp[W] << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}