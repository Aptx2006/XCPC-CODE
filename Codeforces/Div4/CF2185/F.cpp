// Problem: F. BattleCows
// Contest: Codeforces - Codeforces Round 1074 (Div. 4)
// URL: https://codeforces.com/contest/2185/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, q, m, t, ar[MAXN], ans, cnt, k;

using P = pair<int, int>;
vector<vector<P>> lv;

void init(int n, vector<int>& a) {
    lv.clear();
    vector<P> l0;
    for (int x : a) l0.push_back({x, 0});
    lv.push_back(l0);
    while (lv.back().size() > 1) {
        vector<P> nx;
        auto& c = lv.back();
        for (int i = 0; i < c.size(); i += 2) {
            int l = c[i].first, r = c[i + 1].first;
            nx.push_back({l ^ r, l < r});
        }
        lv.push_back(nx);
    }
}

void upd(int p, int v, int n) {
    lv[0][p].first = v;
    int cp = p;
    for (int i = 1; i < lv.size(); i++) {
        cp >>= 1;
        int l = lv[i - 1][cp * 2].first, r = lv[i - 1][cp << 1 | 1].first;
        lv[i][cp] = {l ^ r, l < r};
    }
}

int calc(int p, int n) {
    int pos = 0, sz = 1;
    int cp = p;
    for (int i = 1; i < lv.size(); i++) {
        int s = cp % 2;
        int pp = cp >> 1;
        if (lv[i][pp].second == s) pos += sz;
        cp = pp;
        sz <<= 1;
    }
    return (1 << n) - 1 - pos;
}

void solve() {
    cin >> n >> q;
    vector<int> a(1 << n);
    for (auto& x : a) cin >> x;
    init(n, a);
    while (q--) {
        int b, c;
        cin >> b >> c;
        b--;
        int o = lv[0][b].first;
        upd(b, c, n);
        cout << calc(b, n) << '\n';
        upd(b, o, n);
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
