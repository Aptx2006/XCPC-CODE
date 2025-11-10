// Problem: CF 2121 E
// Contest: Codeforces - Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/E
// StartTime 2025-06-17 23:25:03
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

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
int dp[10][2][2];
string s1, s2;
int dfs(int pos, int oka, int okb) {
  if (pos == n) return 0;
  if (dp[pos][oka][okb] != -1) return m;
  int l = oka ? (s1[pos] - '0') : 0;
  int r = okb ? (s2[pos] - '0') : 9;
  int res = INT_MAX;
  range(l, r) {
    int okaa = oka and (j == s1[pos] - '0'),
        okbb = okb and (j == s2[pos] - '0');
    int cost = (j == s1[pos] - '0') + (j == s2[pos] - '0');
    // int cur = dfs(pos + 1, okaa, okbb);
    res = min(res, dfs(pos + 1, okaa, okbb) + cost);
  }
  return dp[pos][oka][okb] = res;
}
void solve() {
  cin >> s1 >> s2;
  n = s1.length();
  memset(dp, -1, sizeof dp);
  cout << dfs(0, 1, 1) << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
