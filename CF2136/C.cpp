// Problem: C. Against the Difference
// Contest: Codeforces - Codeforces Round 1046 (Div. 2)
// URL: https://codeforces.com/contest/2136/problem/C
// StartTime 2025-08-28 22:55:03
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

const int MAXN = 2e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
  cin >> n;
  forrr(n) cin >> ar[i];
  vector<int> G[n + 1];
  forrr(n) G[ar[i]].pb(i);
  vector<point> pos[n + 1];
  forrr(n) {
    for (int j = i - 1; j < G[i].size(); j++) {
      k = G[i][j + 1 - i];
      pos[G[i][j]].pb({k, i});
    }
  }
  vector<int> dp(n + 1), mx(n + 1);
  forrr(n) {
    for (auto [x, y] : pos[i]) {
      mx[i] = max(mx[i], dp[x - 1] + y);
    }
    dp[i] = max(dp[i - 1], mx[i]);
  }
  cout << dp[n] << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
