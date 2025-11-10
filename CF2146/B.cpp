// Problem: B. Merging the G
// Contest: Codeforces - Codeforces Round 1052 (Div. 2)
// URL: https://codeforces.com/contest/2146/problem/B
// StartTime 2025-09-21 22:38:08
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
  cin >> n >> m;
  umap<int, int> mp;
  vector<vector<int>> G(n);
  vector<int> masks(n);
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    G[i].resize(l);
    for (int j = 0; j < l; ++j) {
      cin >> G[i][j];
      mp[G[i][j]]++;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (!mp.count(i)) {
      cout << "NO\n";
      return;
    }
  }
  // int tag = (1 << m) - 1;
  cnt = 0;
  for (auto &s : G) {
    bool f = 1;
    for (int x : s) {
      if (mp[x] == 1) {
        f = 0;
        break;
      }
    }
    if (f) {
      cnt++;
      if (cnt >= 2) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
