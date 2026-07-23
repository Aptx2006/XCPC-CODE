// Problem: Sensei and Affection (affection)
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108307/E
// StartTime 2025-08-14 12:55:29
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Coder:Aptx4869
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
/*i32 : -2e9~2e9
i64: -9e18~9e18
ui64: 0~1.8e19*/
typedef unsigned long long ull;
typedef unsigned long long ui64;
typedef long long i64;
typedef long long ll;
#define umap unordered_map
#define forrr(A) for (int i = 1; i <= A; i++)
#define range(s, e) for (int j = s; j <= e; j++)
#define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
#define int i64
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
i64 n, m, t, ar[MAXN], ans, cnt, k;
const i64 inf = 1e18;
void solve() {
  cin >> n >> m;
  vector<i64> a(n);
  for (auto &x : a) cin >> x;

  if (m == 1) {
    i64 mx = a[0];
    for (auto x : a) mx = max(mx, x);
    i64 cc = mx - a[0];
    for (int i = 1; i < n; i++) {
      cc += max(0ll, a[i - 1] - a[i]);
    }
    cout << cc << endl;
  } else {
    i64 mx = a[0];
    for (auto x : a) mx = max(mx, x);
    ans = inf;
    for (int d = 0; d <= 500; d++) {
      i64 x0 = max(0ll, mx - d);
      vector<vector<int>> dp(n, vector<int>(2, inf));

      if (x0 >= a[0]) {
        dp[0][0] = x0 - a[0];
      }
      dp[0][1] = x0 + d - a[0];

      for (int i = 1; i < n; i++) {
        int cc00 = max(0ll, a[i - 1] - a[i]);
        int cc01 = max(0ll, a[i - 1] - a[i] + d);
        int cc10 = max(0ll, a[i - 1] - a[i] - d);
        int cc11 = max(0ll, a[i - 1] - a[i]);

        dp[i][0] = min(dp[i - 1][0] + cc00, dp[i - 1][1] + cc10);
        if (x0 < a[i]) {
          dp[i][0] = inf;
        }
        dp[i][1] = min(dp[i - 1][0] + cc01, dp[i - 1][1] + cc11);
      }
      t = min(dp[n - 1][0], dp[n - 1][1]);
      ans = min(ans, t);
    }
    cout << ans << endl;
  }
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
