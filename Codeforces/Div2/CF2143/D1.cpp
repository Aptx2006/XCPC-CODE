// Problem: D1. Inversion Graph Coloring (Easy Version)
// Contest: Codeforces - Codeforces Round 1051 (Div. 2)
// URL: https://codeforces.com/contest/2143/problem/D1
// StartTime 2025-09-18 00:31:14
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  ans = 0;
  auto isok = [](vector<int> sub) {
    int k = sub.size();
    if (k < 3) return 1;
    for (int j = 0; j < k; j++) {
      bool f = 0;
      for (int i = 0; i < j; i++) {
        if (sub[i] > sub[j]) {
          f = 1;
          break;
        }
      }
      if (!f) continue;
      for (int l = j + 1; l < k; l++)
        if (sub[j] > sub[l]) return 0;
    }
    return 1;
  };
  for (int mask = 0; mask < (1 << n); mask++) {
    vector<int> sub;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        sub.pb(a[i]);
      }
    }
    if (isok(sub)) ans = (ans + 1) % MOD;
  }

  cout << ans << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
