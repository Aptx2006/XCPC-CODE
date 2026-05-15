#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

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