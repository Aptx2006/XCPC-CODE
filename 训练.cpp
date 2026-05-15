#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

<<<<<<< HEAD
const i64 MOD = 998244353;

int n;
i64 cnt = 1, ans;

void solve() {
	cin >> n;
	vector<i64> a(n + 1);
	for(int i = 1; i < n; i++) cin >> a[i];

	auto qpow = [&](i64 a, i64 b) {
		i64 res = 1;
		while(b) {
			if(b & 1) (res *= a) %= MOD;
			(a *= a) %= MOD;
			b >>= 1;
		}
		return res;
	};
	auto inv = [&](i64 a) {
		return qpow(a, MOD - 2);
	};

	unordered_map<i64, i64> f;
	f[n - 1] = f[n] = 1;

	for(int i = n - 2; i >= 1; i--) {
		i64 j = i + a[i], x = f[j];
		if(a[i] == a[i + 1]) {
			(cnt *= n - i - 1) %= MOD;
			(f[j] += inv(n - i - 1) * x) %= MOD;
			(f[i] += inv(n - i - 1) * x) %= MOD;
		} else {
			f.clear();
			f[j] = f[i] = x;
		}
	}

	for(int i = 1; i <= n; i++) (ans += f[i]) %= MOD;
	cout << ans * cnt % MOD << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
=======
const int INF = 1e9;
int n, m, k;            

void solve() {
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    vector<i64> dp(n, INF);
    dp[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--) {
        for(auto &[v, w]: g[i]) {
            dp[i] = min(dp[i], dp[v] + w);
        }
    }
    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
>>>>>>> 979334818d779a782710f1da9b1a801c88aab226
