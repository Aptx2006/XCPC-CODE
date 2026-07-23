// Problem: 小月的前缀
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125084/D
// StartTime 2025-12-19 20:24:26
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Coder:Aptx4869
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
ui64: 0~1.8e19*/
typedef unsigned long long ull;
typedef unsigned long long ui64;
typedef long long i64;
typedef long long ll;
#define umap unordered_map
#define forrr(a) for (int i = 1; i <= a; i++)
#define range(s, e) for (int j = s; j <= e; j++)
#define endl "\n"
#define debug(a) cout << #a << "==" << a << "\n";
#define pb push_back
#define point pair<int, int>
#define all(a) a.begin(), a.end()
#define eps(a) fixed << setprecision(a)
#define nextp(a) next_permutation(a.begin(), a.end())
#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m;

struct FWT {
    vector<int> tree;
    int size;

    FWT(int n) : size(n), tree(n + 2, 0) {}

    void add(int rk, int val) {
        for (; rk <= size; rk += rk & -rk) tree[rk] += val;
    }

    int qry(int rk, int res = 0) {
        for (; rk > 0; rk -= rk & -rk) res += tree[rk];
        return res;
    }

    int sum(int l, int r) {
        if (l > r) return 0;
        return qry(r) - qry(l - 1);
    }
};

struct Query {
    int L, R, idx;
    int val;
    int block;
};

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<int> pre(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; ++i) {
        pre[i + 1] = pre[i] + a[i % n];
    }

    vector<int> spre = pre;
    sort(all(spre));
    spre.erase(unique(spre.begin(), spre.end()), spre.end());
    m = spre.size();

    auto getrk = [&](ll x) {
        return lower_bound(spre.begin(), spre.end(), x) - spre.begin() + 1;
    };

    vector<Query> qs(n);
    // int sz = sqrt(2 * n) + 1;
    int sz = n / sqrt(m + 1);
    for (int r = 0; r < n; ++r) {
        int L = r + 1, R = r + n;
        qs[r] = {L, R, r, pre[r], L / sz};
    }

    sort(qs.begin(), qs.end(), [](auto& a, auto& b) {
        if (a.block != b.block) return a.block < b.block;
        return (a.block & 1) ? (a.R > b.R) : (a.R < b.R);
    });

    FWT cnt(m);
    vector<int> ans(n, 0);
    int curL = 1, curR = 0;

    for (auto& q : qs) {
        int L = q.L;
        int R = q.R;
        int idx = q.idx;
        ll val = q.val;

        while (curR < R) {
            curR++;
            int rk = getrk(pre[curR]);
            // cnt[rk]++;
            cnt.add(rk, 1);
        }
        while (curR > R) {
            int rk = getrk(pre[curR]);
            // cnt[rk]--;
            cnt.add(rk, -1);
            curR--;
        }
        while (curL > L) {
            curL--;
            int rk = getrk(pre[curL]);
            // cnt[rk]++;
            cnt.add(rk, 1);
        }
        while (curL < L) {
            int rk = getrk(pre[curL]);
            // cnt[rk]--;
            cnt.add(rk, -1);
            curL++;
        }

        int crk = getrk(val);
        // int cost = 0;
        // for (int rk = crk + 1; rk <= m; ++rk) {
        // cost += cnt[rk];
        // }
        ans[idx] = cnt.sum(crk + 1, m);
    }

    auto mx = max_element(all(ans));
    cout << mx - ans.begin() << " " << *mx << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;
    // cin >> times;
    while (times--) solve();
    return 0;
}
