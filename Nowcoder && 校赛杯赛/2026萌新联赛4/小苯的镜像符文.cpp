#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    vector<i64> a(26);
    for(auto &x: a) cin >> x;
    vector<i64> dp(n + 5, 1e18);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + a[s[i] - 'a']);
        for(int len = 1; i - len + 1 >= 0 and i + len < n; len++) {
            if(s[i - len + 1] != s[i + len]) break;
            dp[i + len + 1] = min(dp[i + len + 1], dp[i + 1] + k);
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}