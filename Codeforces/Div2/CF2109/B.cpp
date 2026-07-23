// Problem: CF 2109 B
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/contest/2109/problem/B
// StartTime 2025-05-17 22:45:08
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Coder:unAptx4869
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bint size_t
#define forrr for (int i = 1; i <= n; i++)

const int MAXN = 1e5, MOD = 1e9 + 7;
int n, t, ar[MAXN], ans, cnt, k;
int m, a, b;
int cut(int x) {
  int r = 0;
  while (x != 1) {
    r++;
    x = (x + 1) / 2;
  }
  return r;
}
void solve() {
  cnt = 0;
  int cnt1 = 0;
  cin >> n >> m >> a >> b;
  cnt += cut(max(1ll, min(a, n - a + 1))) + cut(m);
  if (n != 1) cnt++;
  cnt1 += cut(max(1ll, min(b, m - b + 1))) + cut(n);
  if (m != 1) cnt1++;
  cout << min(cnt, cnt1) << "\n";
  return;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) solve();
  return 0;
}
