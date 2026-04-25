#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

const int B = 30;
int T, n, m;

void solve() {
	cin >> n >> m;
	int p[B + 1]{0};
	auto insert = [&](int x) {
		for(int i = B; i >= 0; i--) {
			if(!(x >> i & 1)) continue;
			if(!p[i]) {
				p[i] = x;
				return;
			}
			x ^= p[i];
		}
	};

	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		insert(x ^ y ^ w);
	}

	int ans = 1 ^ n;
	for(int i = B; i >= 0; i--) {
        if(!p[i]) continue;
        ans = min(ans, ans ^ p[i]);
	}
    cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(cin >> T; T--; solve());
	return 0;
}
