// Problem: D. For the Champion
// Contest: Codeforces - Codeforces Round 1046 (Div. 2)
// URL: https://codeforces.com/contest/2136/problem/D
// StartTime 2025-08-28 23:33:33
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
// #define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
#define int i64
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
const int inf = 1000000000;
void solve() {
  cin >> n;
  vector<point> pos;
  forrr(n) {
    int x, y;
    cin >> x >> y;
    pos.pb({x, y});
  }
  point pl, pr;
  int mx = LLONG_MIN;
  for (auto [x, y] : pos)
    if (x + y > mx) {
      mx = x + y;
      pr = {x, y};
    }
  mx = LLONG_MIN;
  for (auto [x, y] : pos)
    if (-x + y > mx) {
      mx = -x + y;
      pl = {x, y};
    }
  auto move = [&](char ch) {
    cout << "? " << ch << " " << inf << endl;
    int d;
    cin >> d;
    if (d == -1) exit(0);
    return d;
  };
  int dl, dr;
  move('U');
  move('U');
  move('R');
  dr = move('R');
  move('L');
  move('L');
  move('L');
  dl = move('L');

  int rr = dr + pr.first + pr.second;
  int ll = dl - pl.first + pl.second;
  int x, y;
  y = (ll + rr) / 2 - 4 * inf;
  x = (rr - ll) / 2;
  cout << "! " << x << " " << y << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
