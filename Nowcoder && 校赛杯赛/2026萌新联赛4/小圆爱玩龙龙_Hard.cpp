#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m >> k;
    vector<pair<i64, i64> > a(n);
    i64 sum = 0;
    for(auto &[x, y]: a) {
        cin >> x >> y;
        sum += y;
    }
    if(k >= n) {
        cout << sum << "\n";
        return;
    }
    if(k == 0) {
        vector<i64> dp(sum + 1, 1e18);
        dp[0] = 0;
        for(auto [w, v]: a) {
            for(int j = sum; j >= v; j--) {
                dp[j] = min(dp[j], dp[j - v] + w);
            }
        }
        i64 ans = 0;
        for(int j = 0; j <= sum; j++) {
            if(dp[j] <= m) ans = max(ans, (i64)j);
        }
        cout << ans << "\n";
        return;
    }
    sort(all(a), greater<>());
    vector<i64> b;
    for(int i = 0; i < n; i++) b.push_back(a[i].second);
    sort(all(b), greater<i64>());
    i64 ans = 0;
    for(int i = 0; i < k; i++) ans += b[i];
    vector<i64> pre;
    priority_queue<i64, vector<i64>, greater<i64>> pq;
    i64 sum_ = 0;
    for(auto [w, v]: a) {
        pre.push_back(sum_);
        pq.push(v);
        sum_ += v;
        if((int)pq.size() > k - 1) {
            sum_ -= pq.top();
            pq.pop();
        }
    }

    vector<i64> dp(sum + 1, 1e18);
    dp[0] = 0;
    i64 curv = 0;
    for(int i = n - 1; i >= k - 1; i--) {
        i64 ansv = 0;
        for(int j = curv; j >= 0; j--) {
            if(dp[j] <= m) {
                ansv = j;
                break;
            }
        }
        auto [w, v] = a[i];
        ans = max(ans, pre[i] + v + ansv);
        for(int j = curv + v; j >= v; j--) {
            dp[j] = min(dp[j], dp[j - v] + w);
        }
        curv += v;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}