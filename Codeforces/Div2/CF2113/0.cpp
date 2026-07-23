// Problem: CF 2113 A
// Contest: Codeforces - Codeforces Round 1031 (Div. 2)
// URL: https://codeforces.com/contest/2113/problem/0
// StartTime 2025-06-15 17:05:12
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
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
  ans = 0;
  i64 k, a, b, x, y;
  cin >> k >> a >> b >> x >> y;
  if (x < y) {
    if (k >= a) ans += (k - a) / x + 1;
    k -= ans * x;
    if (k >= b) ans += (k - b) / y + 1;
  } else {
    if (k >= b) ans += (k - b) / y + 1;
    k -= ans * y;
    if (k >= a) ans += (k - a) / x + 1;
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
