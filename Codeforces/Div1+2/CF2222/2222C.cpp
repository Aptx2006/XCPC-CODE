#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> aa = a;
	sort(all(aa));
	int mid = aa[n / 2];
	vector<int> same(n + 1), pre(n + 1);
	for(int i = 0; i < n; i++) {
		pre[i + 1] = pre[i];
        if(a[i] > mid) pre[i + 1]++;
        else if(a[i] < mid) pre[i + 1]--;
		same[i + 1] = same[i] + (a[i] == mid);
	}
	vector<int> dp(n + 1, -1); // 前i个数最多能分dp[i]段
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = (~i & 1); j < i; j += 2) {
            //if(~i & 1) continue;
			if(dp[j] != -1) {
				cnt = same[i] - same[j];
				if(cnt - abs(pre[i] - pre[j]) >= 1) {
					if(dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
				}
			}
		}
	}
	cout << dp[n] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while(T--) solve();
	return 0;
}
