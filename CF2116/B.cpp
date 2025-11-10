// Problem: CF 2116 B
// Contest: Codeforces - Codeforces Round 1028 (Div. 2)
// URL: https://codeforces.com/contest/2116/problem/B
// StartTime 2025-05-31 22:44:37
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define nextp(A) next_permutation(A.begin(), A.end())

const int MAXN = 1e5 + 5, MOD = 998244353;
int n, m, t, ar[MAXN], ans, cnt, k;
i64 qpow(i64 a, i64 b, i64 res = 1) {
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

void solve() {
  cin >> n;
  vector<int> p(n + 1), q(n + 1);
  forrr(n) cin >> p[i - 1];
  forrr(n) cin >> q[i - 1];
  vector<i64> maxp(n + 1), maxq(n + 1), ans(n + 1);
  for (int i = 1; i < n; i++) {
    if (p[i] < p[maxp[i - 1]])
      maxp[i] = maxp[i - 1];
    else
      maxp[i] = i;
    if (q[i] < q[maxq[i - 1]])
      maxq[i] = maxq[i - 1];
    else
      maxq[i] = i;
  }
  for (int i = 0; i < n; i++) {
    if (p[maxp[i]] == q[maxq[i]]) {
      if (q[i - maxp[i]] >= p[i - maxq[i]])
        ans[i] = qpow(2, p[maxp[i]]) + qpow(2, q[i - maxp[i]]);
      else
        ans[i] = qpow(2, q[maxq[i]]) + qpow(2, p[i - maxq[i]]);
    } else if (p[maxp[i]] > q[maxq[i]])
      ans[i] = qpow(2, p[maxp[i]]) + qpow(2, q[i - maxp[i]]);
    else
      ans[i] = qpow(2, q[maxq[i]]) + qpow(2, p[i - maxq[i]]);
    ans[i] %= MOD;
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
