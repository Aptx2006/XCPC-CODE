#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

struct Interval {
    i64 l, r;
    i64 len() const { return r - l + 1; }
};

void solve() {
    i64 L; 
    cin >> L >> n >> m;

    vector< pair<int, int> > a(n);
    for(auto &[l, r]: a) cin >> l >> r;
    vector<i64> b(m);
    for(auto &x: b) cin >> x;
    sort(all(b));

    vector< pair<int, int> > aa;
    for(auto& iv : a) {
        auto it = lower_bound(all(b), iv.first);
        if(it != b.end() and *it <= iv.second) {
            aa.push_back(iv);
        }
    }

    if(aa.empty()) {
        cout << 0 << "\n";
        return;
    }

    sort(all(aa), [](auto &o1, auto o2) { return o1.second < o2.second;});

    i32 sz = aa.size();
    vector<i64> p(sz, -1), R(sz);

    for(int i = 0; i < sz; i++) 
        R[i] = aa[i].second;
    for(i32 i = 0; i < sz; i++) {
        i32 pos = lower_bound(all(R),  aa[i].first) - R.begin();
        if(pos >= 1) {
            p[i] = pos - 1;
        }
    }
    vector<i64> dp(sz, 0);
    for (i32 i = 0; i < sz; i++) {
        i64 len = aa[i].second - aa[i].first + 1;
        if(p[i] != -1) len += dp[p[i]];
        if(i == 0) dp[i] = 0;
        else dp[i] = dp[i - 1];
        dp[i] = max(dp[i], len);
    }

    cout << dp[sz - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}