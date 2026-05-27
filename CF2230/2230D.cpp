#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    vector< vector<int> > mp(n+5);
    for(int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
        if(a[i] != b[i]) mp[b[i]].push_back(i);
    }

    vector<int> dp(n, n - 1); // 第i天若成功 则最多可以往后看到第dp[i]天

    for(int k = n; k >= 1; k--) {
        // 已经看完了第k集
        for(auto p : mp[k]) {
            if(a[p] != b[p]) continue;
            auto it = upper_bound(all(mp[k + 1]), p);
            if(it == mp[k + 1].end()) {
                dp[p] = n - 1; // 看到最后一天都没事
            } else {
                int pp = *it;
                if(a[pp] == b[pp]) {
                    dp[p] = dp[pp]; 
                } else {
                    dp[p] = pp - 1; 
                }
            }
        }
    }

    i64 ans = 0;
    for(int L = 0; L < n; L++) {
        auto it = lower_bound(all(mp[1]), L);
        if(it == mp[1].end()) {
            ans += n - L;
            continue;
        }
        int R = n - 1;
        int p = *it;
        if(a[p] == b[p]) {
            R = dp[p]; 
        }else {
            R = p - 1; 
        }
        ans += (R - L + 1);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
