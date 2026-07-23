#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 INF = 1e18;
i64 n, m;

void solve() {
    cin >> n >> m;
    vector<i64> a(n), b(n + 1);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<i64> pre(n + 1), sh(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1] * b[i - 1];
        sh[i] = sh[i - 1] + a[i - 1] * b[i];
    }

    if (sh[n] >= m) {
        cout << "0\n";
        return;
    }

    auto ok = [&](i64 v) {
        int p = lower_bound(a.begin(), a.end(), v) - a.begin();
        return pre[p] + v * b[p] + (sh[n] - sh[p]) >= m;
    };

    i64 l = 1, r = m, ans = INF;
    while (l <= r) {
        i64 mid = (l + r) >> 1;
        if (ok(mid)) {
            r = mid - 1;
            ans = min(ans, mid);
        }else {
            l = mid + 1;
        }
    }
    if(ans == INF) ans = 0;
    cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
