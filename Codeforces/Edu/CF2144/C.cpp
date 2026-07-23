// Problem: C. Non-Descending Arrays
// Contest: Codeforces - Educational Codeforces Round 182 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2144/problem/C
// StartTime 2025-09-15 23:02:08
// Memory Limit: 256 MB
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

const int MAXN = 1e4, MOD = 998244353;
int n, m, t, ar[MAXN], b[MAXN], ans, cnt, k;
int dp[MAXN][2];
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() {
  cin >> n;
  forrr(n) dp[i][0] = dp[i][1] = 0;
  forrr(n) cin >> ar[i];
  forrr(n) cin >> b[i];
  forrr(n) {
    if (i == 1) {
      dp[1][0] = dp[1][1] = 1;
      continue;
    }
    if (ar[i - 1] <= ar[i] and b[i - 1] <= b[i])
      dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
    if (ar[i - 1] <= b[i] and b[i - 1] <= ar[i])
      dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
    if (b[i - 1] <= ar[i] and ar[i - 1] <= b[i])
      dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
    if (b[i - 1] <= b[i] and ar[i - 1] <= ar[i])
      dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
  }
  ans = (dp[n][0] + dp[n][1]) % MOD;
  cout << ans << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
