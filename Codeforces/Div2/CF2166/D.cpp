// Problem: D. Marble Council
// Contest: Codeforces - Codeforces Round 1064 (Div. 2)
// URL: https://codeforces.com/contest/2166/problem/D
// StartTime 2025-11-17 00:03:48
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Coder:Aptx4869
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
ui64: 0~1.8e19*/
typedef unsigned long long ull;
typedef unsigned long long ui64;
typedef long long i64;
typedef long long ll;
#define umap unordered_map
#define forrr(A) for (int i = 1; i <= A; i++)
#define range(j, e) for (int j = j; j <= e; j++)
#define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
#define int long long
const int MAXN = 1e5 + 5, MOD = 998244353;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() {
  cin >> n;
  vector<int> a(n), buc(n + 1, 0);
  for (int &x : a) {
    cin >> x;
    buc[x]++;
  }
  vector<int> b;
  forrr(n) if (buc[i]) b.pb(buc[i]);
  sort(b.rbegin(), b.rend());
  m = b.size();
  if (m == 0) {
    cout << "0\n";
    return;
  }
  vector<int> pre(m + 1, 0), prep(m + 1, 1), dp(n + 1, 0);
  forrr(m) {
    pre[i] = pre[i - 1] + b[i - 1];
    prep[i] = prep[i - 1] * (b[i - 1] % MOD) % MOD;
  }
  dp[0] = 1, ans = prep[m];
  for (int i = m; i >= 1; i--) {
    int idx = i - 1;
    int val = b[i - 1] - pre[i - 1];
    int l = 0;
    if (val > n)
      l = n + 1;
    else if (val >= 0)
      l = val;
    int sum = 0;
    for (int j = l; j <= n; ++j) {
      sum = (sum + dp[j]) % MOD;
    }
    ans = (ans + prep[i - 1] * sum % MOD) % MOD;
    vector<int> dpp(n + 1, 0);
    for (int j = 0; j <= n; ++j) {
      dpp[j] = (dpp[j] + dp[j]) % MOD;
      int jj = j + b[i - 1];
      if (jj <= n) {
        dpp[jj] = (dpp[jj] + dp[j] * (b[i - 1] % MOD) % MOD) % MOD;
      }
    }
    dp = dpp;
  }
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
