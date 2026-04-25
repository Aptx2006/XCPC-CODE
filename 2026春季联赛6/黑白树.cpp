#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()

struct DSU {
	vector<int> f;
	DSU(int n): f(n+1) { iota(f.begin(), f.end(), 0); }
	int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
	bool merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if(fx == fy) return false;
		f[fx] = fy;
		return true;
	}
};

int T, n, m;

struct Edge {
	int u, v, c;
};

void solve() {
	cin >> n >> m;
	vector<Edge> e(m);
	for(int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].c;
	}

	vector<Edge> e1 = e;
	sort(all(e1), [](const Edge &a, const Edge &b) {
		return a.c > b.c; 
	});
	DSU dsu1(n);
	int minB = 0, cnt1 = 0;
	for(auto &ed : e1) {
		if(dsu1.merge(ed.u, ed.v)) {
			cnt1++;
			if(ed.c == 0) minB++;
		}
	}
	if(cnt1 < n-1) {
		cout << 0 << '\n';
		return;
	}

	vector<Edge> e2 = e;
	sort(all(e2), [](const Edge &a, const Edge &b) {
		return a.c < b.c; 
	});
	DSU dsu2(n);
	int maxB = 0, cnt2 = 0;
	for(auto &ed : e2) {
		if(dsu2.merge(ed.u, ed.v)) {
			cnt2++;
			if(ed.c == 0) maxB++;
		}
	}
	if(cnt2 < n-1) 
		cout << "0\n";
	else
	    cout << maxB - minB + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while(T--) solve();
	return 0;
}
