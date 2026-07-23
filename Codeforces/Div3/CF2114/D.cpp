// Problem: CF 2114 D
// Contest: Codeforces - Codeforces Round  1027 (Div. 3)
// URL: https://codeforces.com/contest/2114/problem/D
// StartTime 2025-05-26 23:34:56
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
#define forrr(A) for (i64 i = 1; i <= A; i++)
#define range(s, e) for (i64 j = s; j <= e; j++)
#define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define poi64 pair<i64, i64>
#define all(A) A.begin(), A.end()
#define nextp(A) next_permutation(A.begin(), A.end())
#define minrr(A) *min_element(all(A))
#define maxrr(A) *max_element(all(A))
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
i64 n, m, t, ar[MAXN], ans, cnt, k;
void solve() {
  cin >> n;
  if (n == 1) {
    cout << 1 << "\n";
    int x, y;
    cin >> x >> y;
  } else {
    vector<i64> a(n, 0), b(n, 0), c(n, 0), d(n, 0);
    for (i64 i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      c[i] = a[i], d[i] = b[i];
    }
    ans = LLONG_MAX;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    range(0, n - 1) {
      i64 x = 0, y = 0;
      if (a[j] == c[0]) {
        x = c[n - 1] - c[1] + 1;
      } else if (a[j] == c[n - 1]) {
        x = c[n - 2] - c[0] + 1;
      } else {
        x = c[n - 1] - c[0] + 1;
      }
      if (b[j] == d[0]) {
        y = d[n - 1] - d[1] + 1;
      } else if (b[j] == d[n - 1]) {
        y = d[n - 2] - d[0] + 1;
      } else {
        y = d[n - 1] - d[0] + 1;
      }
      if (x * y == n - 1) {
        ans = min(ans, x * y + min(x, y));
      } else {
        ans = min(ans, x * y);
      }
    }
    cout << ans << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
