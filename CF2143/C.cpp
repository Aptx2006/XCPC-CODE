// Problem: C. Max Tree
// Contest: Codeforces - Codeforces Round 1051 (Div. 2)
// URL: https://codeforces.com/contest/2143/problem/C
// StartTime 2025-09-17 23:08:36
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
#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() {
  cin >> n;
  vector<vector<int>> G(n + 1);
  vector<int> in(n + 1, 0);

  forrr(n - 1) {
    int u, v, x, y;
    cin >> u >> v >> x >> y;
    if (x >= y) {
      G[u].pb(v), in[v]++;
    } else {
      G[v].pb(u), in[u]++;
    }
  }

  queue<int> q;
  forrr(n) if (!in[i]) q.push(i);

  vector<int> a;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    a.pb(u);
    for (int v : G[u]) {
      in[v]--;
      if (!in[v]) q.push(v);
    }
  }

  vector<int> res(n + 1);
  t = n;
  for (int x : a) {
    res[x] = t;
    t--;
  }

  forrr(n) cout << res[i] << " \n"[i == n];
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
