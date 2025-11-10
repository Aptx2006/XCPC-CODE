// Problem: CF 2109 A
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/contest/2109/problem/0
// StartTime 2025-05-17 22:36:06
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

void solve() {
  cnt = 0;
  bool flag = 1;
  cin >> n;
  forrr { cin >> ar[i]; }
  for (int i = 1; i < n; i++) {
    if (ar[i] == 0 && ar[i + 1] == 0) {
      cout << "YES\n";
      return;
    }
  }
  forrr {
    if (ar[i] != 1) {
      flag = false;
      break;
    }
  }
  cout << ((flag) ? "YES\n" : "NO\n");
  return;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) solve();
  return 0;
}
