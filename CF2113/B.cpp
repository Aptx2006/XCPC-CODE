// Problem: CF 2113 B
// Contest: Codeforces - Codeforces Round 1031 (Div. 2)
// URL: https://codeforces.com/contest/2113/problem/B
// StartTime 2025-06-15 17:16:16
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

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
i64 f1(i64 v, i64 m) { return (v % m + m) % m; }  // 防止负数取余炸了
i64 f2(i64 v, i64 d) {
  if (v >= 0) return v / d;
  return -((d - v - 1) / d);  // 方便整除
}
void solve() {
  i64 w, h, a, b, x1, y1, x2, y2;
  cin >> w >> h >> a >> b;
  cin >> x1 >> y1 >> x2 >> y2;
  bool f = (f1(x1, a) == f1(x2, a)) and
           (f2(x1, a) != f2(x2, a) or (y1 - y2) % b == 0);
  if (!f) {
    f = (f1(y1, b) == f1(y2, b)) and
        (f2(y1, b) != f2(y2, b) or (x1 - x2) % a == 0);
  }
  cout << (f ? "Yes\n" : "No\n");
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
