// Problem: CF 2110 C
// Contest: Codeforces - Codeforces Round 1026 (Div. 2)
// URL: https://codeforces.com/contest/2110/problem/C
// StartTime 2025-05-24 22:55:54
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Coder:unAptx4869
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define bint size_t
#define forrr for (int i = 0; i < n; i++)

const int MAXN = 1e6 + 10, MOD = 1e9 + 7;
int n, t, ar[MAXN], res[MAXN], d[MAXN], ans, cnt, k;
pair<int, int> nod[MAXN];
bool f = 0;
bool dfs(int x, int h) {
  if (x == n) f = 1;
  if (f == 1) return 1;
  if (d[x] != -1) {
    h += d[x];
  } else {
    d[x] = 1, dfs(x, h);
    if (!f) d[x] = 0, dfs(x, h);
  }
  if (h >= nod[x].first and h <= nod[x].second) dfs(x + 1, h);
  return 0;
}
void solve() {
  f = 0;
  cin >> n;
  forrr cin >> d[i];
  forrr cin >> nod[i].first >> nod[i].second;
  dfs(0, 0);
  if (f) {
    forrr cout << d[i] << " \n"[i == n - 1];
  } else
    cout << "-1\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) solve();
  return 0;
}
