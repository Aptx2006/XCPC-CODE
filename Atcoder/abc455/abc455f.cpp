#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

const i64 MOD = 998244353;
const i64 INV2 = (MOD + 1) / 2;

int n, q;

struct Tag {
	i64 add = 0;
	void apply(const Tag &t) {
		add = (add + t.add) % MOD;
	}
};
struct Info {
	i64 sum = 0, sum2 = 0;
	void apply(const Tag &t, int l, int r) {
		i64 len = r - l;
		sum2 = (sum2 + 2 * t.add % MOD * sum % MOD + len % MOD * t.add % MOD * t.add % MOD) % MOD;
		sum = (sum + len % MOD * t.add % MOD) % MOD;
	}
};
Info operator+(const Info &a, const Info &b) {
	return {(a.sum + b.sum) % MOD, (a.sum2 + b.sum2) % MOD};
}

template<class Info, class Tag>
struct LazySegmentTree {
	int n;
	std::vector<Info> info;
	std::vector<Tag> tag;
	LazySegmentTree() : n(0) {}
	LazySegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }
	template<class T>
	LazySegmentTree(std::vector<T> init_) { init(init_); }
	void init(int n_, Info v_ = Info()) { init(std::vector(n_, v_)); }
	template<class T>
	void init(std::vector<T> init_) {
		n = init_.size();
		info.assign(4 << std::__lg(n), Info());
		tag.assign(4 << std::__lg(n), Tag());
		std::function<void(int, int, int)> build = [&](int p, int l, int r) {
			if (r - l == 1) {
				info[p] = init_[l];
				return;
			}
			int m = (l + r) / 2;
			build(2 * p, l, m);
			build(2 * p + 1, m, r);
			pull(p);
		};
		build(1, 0, n);
	}
	void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }
	void apply(int p, const Tag &v, int l, int r) {
		info[p].apply(v, l, r);
		tag[p].apply(v);
	}
	void push(int p, int l, int r) {
		if (tag[p].add == 0 || r - l == 1) return;
		int m = (l + r) / 2;
		apply(2 * p, tag[p], l, m);
		apply(2 * p + 1, tag[p], m, r);
		tag[p] = Tag();
	}
	void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
		if (l >= y || r <= x) return;
		if (l >= x && r <= y) { apply(p, v, l, r); return; }
		int m = (l + r) / 2;
		push(p, l, r);
		rangeApply(2 * p, l, m, x, y, v);
		rangeApply(2 * p + 1, m, r, x, y, v);
		pull(p);
	}
	Info rangeQuery(int p, int l, int r, int x, int y) {
		if (l >= y || r <= x) return Info();
		if (l >= x && r <= y) return info[p];
		int m = (l + r) / 2;
		push(p, l, r);
		return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
	}
	void rangeApply(int l, int r, const Tag &v) { rangeApply(1, 0, n, l, r, v); }
	Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
};

void solve() {
	cin >> n >> q;
	LazySegmentTree<Info, Tag> st(n);
	while (q--) {
		int l, r;
		i64 a;
		cin >> l >> r >> a;
		st.rangeApply(l - 1, r, Tag{a});
		auto res = st.rangeQuery(l - 1, r);
		i64 ans = ((res.sum * res.sum % MOD - res.sum2) % MOD + MOD) % MOD;
		ans = ans * INV2 % MOD;
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
