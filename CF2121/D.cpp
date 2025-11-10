// Problem: CF 2121 D
// Contest: Codeforces - Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/D
// StartTime 2025-06-18 00:00:50
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
#define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], b[MAXN], ans, cnt, k;

void solve() {
  cin >> n;
  forrr(n) cin >> ar[i];
  forrr(n) cin >> b[i];
  vector<point> res;
  forrr(n) {
    if (ar[i] > b[i]) swap(ar[i], b[i]), res.pb({3, i});
  }
  for (int i = 2; i <= n; i++) {
    int j = i;
    while (j > 1 and ar[j] < ar[j - 1]) {
      swap(ar[j], ar[j - 1]);
      res.pb({1, j - 1});
      j--;
    }
  }
  for (int i = 2; i <= n; i++) {
    int j = i;
    while (j > 1 and b[j] < b[j - 1]) {
      swap(b[j], b[j - 1]);
      res.pb({2, j - 1});
      j--;
    }
  }
  cout << res.size() << endl;
  for (auto x : res) cout << x.first << " " << x.second << "\n";
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
