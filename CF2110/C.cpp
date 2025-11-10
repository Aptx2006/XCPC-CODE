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

const int MAXN = 2e5 + 10, MOD = 1e9 + 7;
int n, t, ar[MAXN], res[MAXN], d[MAXN], ans, cnt, k;
// bool dp[MAXN + 2][500], ch[MAXN + 2][500];
//  void solve() {
//  cin >> n;
//  forrr cin >> d[i];
//  vector<pair<int, int>> nod(n);
//  map<int, bool> dp[n + 2], ch[n + 2];
//  forrr cin >> nod[i].first >> nod[i].second;
//  dp[0][0] = 1;
//  int newh;
//  forrr {
//  int l = nod[i].first, r = nod[i].second;
//  for (auto [h, f] : dp[i]) {
//  if (!f) continue;
//  if (d[i] == 0 or d[i] == 1) {
//  newh = h + d[i];
//  if (newh >= l and newh <= r) {
//  dp[i + 1][newh] = 1;
//  ch[i + 1][newh] = d[i];
//  }
//  } else {
//  // 0 or 1
//  newh = h;
//  if (newh >= l && newh <= r) dp[i + 1][newh] = 1, ch[i + 1][newh] = 0;
//  newh = h + 1;
//  if (newh >= l && newh <= r) dp[i + 1][newh] = 1, ch[i + 1][newh] = 1;
//  }
//  }
//  }
//  if (dp[n].empty()) {
//  cout << "-1\n";
//  return;
//  }
//  newh = dp[n].begin()->first;
//  for (int i = n; i > 0; i--) {
//  res[i - 1] = ch[i][newh];
//  newh -= res[i - 1];
//  }
//  forrr cout << res[i] << " \n"[i == n - 1];
//  }
//
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    forrr cin >> d[i];
    vector<pair<int, int>> nod(n);
    map<int, bool> dp[n + 2], ch[n + 2];
    int maxh = -1;
    forrr cin >> nod[i].first >> nod[i].second, maxh = max(maxh, nod[i].second);
    dp[0][0] = 1;
    int newh;
    forrr {
      int l = nod[i].first, r = nod[i].second;
      for (int h = 0; h <= maxh; h++ /*auto [h, f] : dp[i]*/) {
        if (!dp[i][h]) continue;
        if (d[i] == 0 or d[i] == 1) {
          newh = h + d[i];
          if (newh >= l and newh <= r) {
            dp[i + 1][newh] = 1;
            ch[i + 1][newh] = d[i];
          }
        } else {
          // 0 or 1
          newh = h;
          if (newh >= l && newh <= r) dp[i + 1][newh] = 1, ch[i + 1][newh] = 0;
          newh = h + 1;
          if (newh >= l && newh <= r) dp[i + 1][newh] = 1, ch[i + 1][newh] = 1;
        }
      }
    }
    newh = -1;
    for (int h = 0; h <= maxh; h++ /*auto [h, f] : dp[i]*/)
      if (dp[n][h]) {
        newh = h;
        break;
      }
    if (newh == -1) {
      cout << "-1\n";
      continue;
    }
    for (int i = n; i > 0; i--) {
      res[i - 1] = ch[i][newh];
      newh -= res[i - 1];
    }
    forrr cout << res[i] << " \n"[i == n - 1];
  }
  return 0;
}
