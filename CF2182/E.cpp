// Problem: E. New Year's Gifts
// Contest: Codeforces - Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2182/problem/E
// Memory Limit: 512 MB
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

const int MAXN = 2E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ans, cnt, k;
struct nod {
    int x, val;
};

void solve() {
    cin >> n >> m >> k;
    vector<int> a(m);
    for (auto &x : a) cin >> x;
    sort(all(a), greater<int>());
    vector<nod> b(n);
    int sumy = 0;
    for (int y, z, i = 0; i < n; i++) {
        cin >> b[i].x >> y >> z;
        b[i].val = z - y;
        sumy += y;
    }
    // iota(all(id), 0);
    sort(all(b), [&](auto o1, auto o2) { return o1.x > o2.x; });
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> st;
    int p = 0;
    for (auto &[x, val] : b) {
        pq.push(val);
        while (p < m and a[p] >= x) p++;
        if (p < pq.size()) st.push_back(pq.top()), pq.pop();
    }
    sort(all(st));
    ans = pq.size();
    sumy = k - sumy;
    for (auto &x : st) {
        if (sumy >= x) {
            sumy -= x;
            ans++;
        } else
            break;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
