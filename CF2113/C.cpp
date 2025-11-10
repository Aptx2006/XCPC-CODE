// Problem: CF 2113 C
// Contest: Codeforces - Codeforces Round 1031 (Div. 2)
// URL: https://codeforces.com/contest/2113/problem/C
// StartTime 2025-06-15 17:55:11
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
vector<vector<int>> pref;

int f(int x1, int y1, int x2, int y2) {
  if (x1 > x2 or y1 > y2) return 0;
  return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] +
         pref[x1][y1];
}
void solve() {
  cin >> n >> m >> k;
  vector<string> G(n);
  for (int i = 0; i < n; ++i) {
    cin >> G[i];
  }
  pref.assign(n + 1, vector<int>(m + 1, 0));
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int add = (G[i][j] == 'g') ? 1 : 0;
      sum += add;
      pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + add;
    }
  }
  int bestLoss = INT_MAX;
  int inner = k - 1;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (G[x][y] == '.') {
        int x1 = max(0, x - inner);
        int y1 = max(0, y - inner);
        int x2 = min(n - 1, x + inner);
        int y2 = min(m - 1, y + inner);
        int l1 = f(x1, y1, x2, y2);
        bestLoss = min(bestLoss, l1);
      }
    }
  }
  cout << (sum - bestLoss) << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
