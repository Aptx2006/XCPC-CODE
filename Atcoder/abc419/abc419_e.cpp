// Problem: AT ABC419 E
// Contest: AtCoder - AtCoder Beginner Contest 419
// URL: https://atcoder.jp/contests/abc419/tasks/abc419_e
// StartTime 2025-08-16 20:39:55
// Memory Limit: 1024 MB
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
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
  cin >> n >> m >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<int>> b(k);
  for (int i = 0; i < n; i++) {
    b[i % k].pb(a[i] % m);
  }

  vector p(k, vector<int>(m, 0));
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      int cost = 0;
      for (int x : b[i]) {
        cost += (j - x + m) % m;
      }
      p[i][j] = cost;
    }
  }

  vector dp(k + 1, vector<int>(m, LLONG_MAX));
  dp[0][0] = 0;

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j] == LLONG_MAX) continue;
      for (int x = 0; x < m; x++) {
        int ns = (j + x) % m;
        int cost = dp[i][j] + p[i][x];
        dp[i + 1][ns] = min(cost, dp[i + 1][ns]);
      }
    }
  }

  cout << dp[k][0] << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  // cin >> times;
  while (times--) solve();
  return 0;
}
