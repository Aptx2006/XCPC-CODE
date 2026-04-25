#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int n, q;

struct FHQ {
	struct Node {
		int l, r, fa, sz, pri;
	};

	vector<Node> t;

	FHQ(int n = 0) {
		t.assign(n + 1, {0, 0, 0, 0, 0});
		mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
		for(int i = 1; i <= n; i++) {
			t[i].sz = 1;
			t[i].pri = (int)rng();
		}
	}

	int sz(int x) {
		return x ? t[x].sz : 0;
	}

	void pull(int x) {
		t[x].sz = 1 + sz(t[x].l) + sz(t[x].r);
		if(t[x].l) t[t[x].l].fa = x;
		if(t[x].r) t[t[x].r].fa = x;
	}

	int merge(int a, int b) {
		if(!a || !b) {
			int x = a ? a : b;
			if(x) t[x].fa = 0;
			return x;
		}
		if(t[a].pri < t[b].pri) {
			t[a].r = merge(t[a].r, b);
			pull(a);
			t[a].fa = 0;
			return a;
		}
		t[b].l = merge(a, t[b].l);
		pull(b);
		t[b].fa = 0;
		return b;
	}

	pair<int, int> split(int x, int k) {
		if(!x) return {0, 0};
		int ls = sz(t[x].l);
		if(k <= ls) {
			auto [a, b] = split(t[x].l, k);
			t[x].l = b;
			pull(x);
			if(a) t[a].fa = 0;
			t[x].fa = 0;
			return {a, x};
		}
		auto [a, b] = split(t[x].r, k - ls - 1);
		t[x].r = a;
		pull(x);
		if(b) t[b].fa = 0;
		t[x].fa = 0;
		return {x, b};
	}

	int root(int x) {
		while(t[x].fa) x = t[x].fa;
		return x;
	}

	int pos(int x) {
		int res = sz(t[x].l) + 1;
		while(t[x].fa) {
			int p = t[x].fa;
			if(t[p].r == x) res += sz(t[p].l) + 1;
			x = p;
		}
		return res;
	}
};

void solve() {
	cin >> n >> q;

	FHQ fhq(n);

	vector<int> pr(n + 1), rp(n + 1);
	for(int i = 1; i <= n; i++) {
		pr[i] = i;
		rp[i] = i;
	}

	while(q--) {
		int c, p;
		cin >> c >> p;

		int sr = fhq.root(c), dr = fhq.root(p);
		int sp = rp[sr], dp = rp[dr];

		int k = fhq.pos(c);
		auto [a, b] = fhq.split(sr, k - 1);
		int nd = fhq.merge(dr, b);

		rp[sr] = 0;
		rp[dr] = 0;

		pr[sp] = a;
		if(a) rp[a] = sp;

		pr[dp] = nd;
		rp[nd] = dp;
	}

	for(int i = 1; i <= n; i++) {
		int rt = pr[i];
		cout << (rt ? fhq.t[rt].sz : 0) << " \n"[i == n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
