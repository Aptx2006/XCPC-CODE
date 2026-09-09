#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct BIT {
    const int inf = 1e9;
    vector<int> w;
    int n;

    BIT(int n = 0) : n(n), w(n + 1, inf) {}
    void init(int n_) {
        n = n_;
        w.assign(n + 1, inf);
    }
    void add(int x, int v) {
        for (; x <= n; x += x & -x) {
            w[x] = min(w[x], v);
        }
    }
    int ask(int x) {
        int ans = inf;
        for (; x; x -= x & -x) {
            ans = min(ans, w[x]);
        }
        return ans;
    }
};

struct BIT2 {
    const int inf = 1e9;
    int n;
    vector<vector<int>> ys;
    vector<BIT> w;

    BIT2(int n, const vector<int> &x, const vector<int> &y) : n(n), ys(n + 1), w(n + 1) {
        for (int j = 0; j < (int)x.size(); j++) {
            for (int i = x[j]; i <= n; i += i & -i) {
                ys[i].push_back(y[j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            sort(all(ys[i]));
            ys[i].erase(unique(all(ys[i])), ys[i].end());
            w[i].init(ys[i].size());
        }
    }

    void add(int x, int y, int v) {
        for (int i = x; i <= n; i += i & -i) {
            int p = lower_bound(all(ys[i]), y) - ys[i].begin() + 1;
            w[i].add(p, v);
        }
    }

    int ask(int x, int y) {
        int res = inf;
        for (int i = x; i; i -= i & -i) {
            int p = upper_bound(all(ys[i]), y) - ys[i].begin();
            res = min(res, w[i].ask(p));
        }
        return res;
    }
};

void solve() {
    cin >> n;
    vector<int> x(n + 1), y(n + 1);
    int mn = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        x[i] = x[i - 1] + r - a;
        y[i] = y[i - 1] + r - b;
        mn = min(mn, x[i]);
        mx = max(mx, x[i]);
    }
    for (auto &v: x) v -= mn - 1;

    BIT2 bit(mx - mn + 1, x, y);
    bit.add(x[0], y[0], 0);
    int cost = 0;
    for (int i = 1; i <= n; i++) {
        int best = bit.ask(x[i], y[i]);
        int nxt = min(cost + 1, best);
        if (nxt < best) bit.add(x[i], y[i], nxt);
        cost = nxt;
    }
    cout << n - cost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
