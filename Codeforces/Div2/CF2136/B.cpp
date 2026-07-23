// Problem: B. Like the Bitset
// Contest: Codeforces - Codeforces Round 1046 (Div. 2)
// URL: https://codeforces.com/contest/2136/problem/B
// StartTime 2025-08-28 22:41:24
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
#define int i64
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
  cin >> n >> k;
  string s;
  cin >> s;
  int cur = 0, mxl = 0;
  for (auto x : s) {
    if (x == '1')
      cur++;
    else {
      mxl = max(cur, mxl);
      cur = 0;
    }
  }
  mxl = max(cur, mxl);
  if (mxl >= k) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<int> res(n);
  k = n;
  for (int i = 0; i < n; i++)
    if (s[i] == '0') res[i] = k--;
  for (int i = 0; i < n; i++)
    if (s[i] == '1') res[i] = k--;
  for (int i = 0; i < n; i++) cout << res[i] << " \n"[i == n - 1];
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
