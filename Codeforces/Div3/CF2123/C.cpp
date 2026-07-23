// Problem: CF 2123 C
// Contest: Codeforces - Codeforces Round 1034 (Div. 3)
// URL: https://codeforces.com/contest/2123/problem/C
// StartTime 2025-07-01 23:00:52
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
  vector<int> b(n + 1), c(n + 2);
  forrr(n) cin >> ar[i];
  b[1] = ar[1];
  for (int i = 2; i <= n; i++) b[i] = min(b[i - 1], ar[i]);
  c[n] = ar[n];
  for (int i = n - 1; i >= 1; i--) c[i] = max(c[i + 1], ar[i]);
  forrr(n) cout << (int)(b[i] == ar[i] or c[i] == ar[i]);
  cout << "\n";
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
