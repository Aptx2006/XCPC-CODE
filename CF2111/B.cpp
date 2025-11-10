// Problem: CF 2111 B
// Contest: dpforces - Educational dpforces Round 179 (Rated for Div. 2)
// URL: https://dpforces.com/contest/2111/problem/B
// StartTime 2025-06-03 23:13:17
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// dpr:Aptx4869
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
#define nextp(A) next_permutation(A.begin(), A.end())

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
ll fb[21];
int n, m, t, ar[MAXN], ans, cnt, k;
int dp[300000][4];
void solve() {
  cin >> n >> m;
  string ans;
  int u = fb[n] + fb[n - 1], v = fb[n];
  for (int i = 0; i < m; i++) {
    cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    sort(dp[i], dp[i] + 3);
    if (dp[i][0] >= v and dp[i][1] >= v and dp[i][2] >= u) {
      ans += "1";
    } else
      ans += "0";
  }
  cout << ans << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  fb[1] = 1;
  fb[2] = 2;
  for (int i = 3; i <= 20; i++) fb[i] = fb[i - 1] + fb[i - 2];
  cin >> times;
  while (times--) solve();
  return 0;
}
