// Problem: C. Wrong Binary Search
// Contest: Codeforces - Codeforces Round 1052 (Div. 2)
// URL: https://codeforces.com/contest/2146/problem/C
// StartTime 2025-09-21 23:20:02
// Memory Limit: 256 MB
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
#define range(s, e) for (int j = s; j <= e; j++)
#define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
// #define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() {
  string s;
  cin >> n >> s;
  vector<int> b(n, 0), c(n, 0);
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      b[i] = i + 1, pos = i;
    }
  }
  bool f = 1;
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cnt++;
    } else if (s[i] == '1') {
      if (cnt < 2 and cnt != 0) {
        f = 0;
      }
      cnt = 0;
    }
  }
  if (cnt < 2 and cnt != 0) f = 0;
  cnt = 0;
  if (!f) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int tmp = n;
  for (int i = n - 1; i >= 0; i--) {
    if (b[i] == 0) {
      c[i] = tmp;
    } else {
      tmp = b[i];
    }
  }
  cnt = 1;
  if (pos == 0) {
    cnt = 0;
  }
  for (int i = 0; i < n; i++) {
    if (c[i] != 0) {
      b[i] = c[i] - cnt;
      cnt++;
    } else if (c[i] == 0 && i != pos) {
      cnt = 1;
    } else {
      cnt = 0;
    }
  }
  for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
