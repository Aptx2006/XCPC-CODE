#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m;
const int INF = 1e9;

void solve() {
	cin >> n >> m;
	vector<int> a(n);
	for(auto &x: a) cin >> x;

	int ans = INF;
	vector<int> cnt(m + 1, 0);
	int M = m;

	for(int l = 0, r = 0; r < n; r++) {
		if(a[r] <= m) {
			if(cnt[a[r]] == 0) M--;
			cnt[a[r]]++;
		}
		while(!M) {
			ans = min(ans, r - l + 1);
			if(a[l] <= m) {
				cnt[a[l]]--;
				if(cnt[a[l]] == 0) M++;
			}
			l++;
		}
	}

	if(ans == INF) cout << -1 << '\n';
	else cout << ans - m << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(cin >> T; T--; solve());
	return 0;
}
