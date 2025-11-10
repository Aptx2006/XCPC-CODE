// Problem: CF 2112 B
// Contest: Codeforces - Educational Codeforces Round 180 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2112/problem/B
// StartTime 2025-06-23 22:40:07
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

const int MAXN = 1005 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (abs(a[i] - a[i + 1]) <= 1) {
      cout << 0 << '\n';
      return;
    }
  }
  vector<vector<int>> pmn(n, vector<int>(n));
  vector<vector<int>> pmx(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    pmn[i][i] = a[i];
    pmx[i][i] = a[i];
    for (int j = i + 1; j < n; j++) {
      pmn[i][j] = min(pmn[i][j - 1], a[j]);
      pmx[i][j] = max(pmx[i][j - 1], a[j]);
    }
  }

  int ans = INT_MAX;
  // 枚举一下长度？疑似可以
  forrr(n - 1) {
    if (i == 1) continue;
    for (int L = 0; L <= n - i; L++) {
      int R = L + i - 1;
      if (L > 0) {
        if (pmx[L][R] >= a[L - 1] - 1 and pmn[L][R] <= a[L - 1] + 1) {
          ans = min(ans, i - 1);
        }
      }
      if (R < n - 1) {
        if (pmx[L][R] >= a[R + 1] - 1 and pmn[L][R] <= a[R + 1] + 1) {
          ans = min(ans, i - 1);
        }
      }
    }
  }

  for (int i = 0; i <= n - 2; i++) {
    int min1 = pmn[0][i], max1 = pmx[0][i];
    int min2 = pmn[i + 1][n - 1], max2 = pmx[i + 1][n - 1];
    if (max1 >= min2 - 1 and min1 <= max2 + 1) {
      ans = min(ans, n - 2);
    }
  }
  cout << ((ans == INT_MAX) ? -1 : ans) << endl;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
