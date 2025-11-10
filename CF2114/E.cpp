// Problem: CF 2114 E
// Contest: Codeforces - Codeforces Round  1027 (Div. 3)
// URL: https://codeforces.com/contest/2114/problem/E
// StartTime 2025-05-27 00:12:37
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Coder:unAptx4869
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

const int MAXN = 2e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
vector<ll> g[MAXN];
ll a[MAXN];
ll dp[MAXN][2];

void dfs(int u, int fa) {
  if (fa == -1) {
    dp[u][0] = a[u];
    dp[u][1] = LLONG_MIN;
  } else {
    dp[u][0] = a[u];
    if (dp[fa][1] != LLONG_MIN) {
      dp[u][0] = max(dp[u][0], a[u] - dp[fa][1]);
    }
    dp[u][1] = a[u] - dp[fa][0];
  }
  for (int v : g[u]) {
    if (v != fa) {
      dfs(v, u);
    }
  }
}

void solve() {
  cin >> n;
  forrr(n) {
    g[i].clear();
    dp[i][0] = dp[i][1] = 0;
  }
  forrr(n) cin >> a[i];
  forrr(n - 1) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1);
  forrr(n) cout << max(dp[i][0], dp[i][1]) << " \n"[i == n];
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
