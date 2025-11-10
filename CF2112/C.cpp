// Problem: CF 2112 C
// Contest: Codeforces - Educational Codeforces Round 180 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2112/problem/C
// StartTime 2025-06-23 23:04:48
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
int n, m, t, ar[MAXN];
i64 ans, cnt, k;
void solve() {
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<vector<i64>> b(n, vector<i64>(n, 0));
  for (int i = 0; i < n; i++) {
    b[i][i] = a[i];
    range(i + 1, n - 1) { b[i][j] = max(b[i][j - 1], a[j]); }
  }
  ans = 0;
  if (n >= 3) {
    for (int k = 2; k <= n - 2; k++) {
      i64 X = max(a[k], a[n - 1] - a[k]);
      int i = 0, j = k - 1;
      cnt = 0;
      while (i < j) {
        if (a[i] + a[j] > X) {
          cnt += (j - i);
          j--;
        } else
          i++;
      }
      ans += cnt;
    }

    int idx = n - 1;
    for (int i = 0; i < idx; i++) {
      for (int j = i + 1; j < idx; j++) {
        if (a[i] + a[j] > a[idx]) {
          i64 maxx = 0;
          if (i > 0) {
            maxx = max(maxx, b[0][i - 1]);
          }
          if (i + 1 <= j - 1) {
            maxx = max(maxx, b[i + 1][j - 1]);
          }
          if (j + 1 <= idx - 1) {
            maxx = max(maxx, b[j + 1][idx - 1]);
          }
          if (a[i] + a[j] + a[idx] > maxx) {
            ans++;
          }
        }
      }
    }
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
