#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
	cin >> n;
	vector<int> a(n);
    for(auto &x: a) cin >> x;
	vector<pair<i64, i64>> pos(n);
    pos[0] = {0, 0};
    for(int i = 1; i < n; i++) {
        auto &[x, y] = pos[i - 1];
        pos[i] = {x + a[i - 1], i};
    }
    sort(all(pos));
    vector<int> res(n);
    for(int i = 0; i < n; i++) res[pos[i].second] = n - i;
    for(int i = 0; i < n; i++) cout << res[i] << " \n"[i == n - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while(T--) solve();
	return 0;
}
