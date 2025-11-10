// Problem: CF 2110 A
// Contest: Codeforces - Codeforces Round 1026 (Div. 2)
// URL: https://codeforces.com/contest/2110/problem/A
// StartTime 2025-05-24 22:37:17
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
  cin >> n;
  forrr cin >> ar[i];
  sort(ar + 1, ar + n + 1);
  ans = cnt = 0;
  int f1 = -1, f2 = -1, e1 = -1, e2 = -1;
  if (n == 1)
    cout << "0\n";
  else if (n == 2 and (ar[1] + ar[2]) & 1)
    cout << "1\n";
  else {
    forrr {
      if (ar[i] & 1) {
        if (f1 == -1) f1 = i;
        e1 = i;
      } else if (~ar[i] & 1) {
        if (f2 == -1) f2 = i;
        e2 = i;
      }
    }
    ans = f1 - 1 + n - e1, cnt = f2 - 1 + n - e2;
    cout << min(ans, cnt) << "\n";
  }
  return;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) solve();
  return 0;
}
