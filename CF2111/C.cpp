// Problem: CF 2111 C
// Contest: Codeforces - Educational Codeforces Round 179 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2111/problem/C
// StartTime 2025-06-03 23:01:24
// Memory Limit: 512 MB
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
#define nextp(A) next_permutation(A.begin(), A.end())
const int MAXN = 5e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
#define int i64
void solve() {
  cin >> n;
  i64 ans = 1e12;
  vector<int> buc;
  vector<pair<point, int>> Q;
  cin >> ar[1];
  int temp = ar[1], l = 1;
  cnt = 1;
  forrr(n) {
    if (i == 1) continue;
    cin >> ar[i];
    if (ar[i] == temp) {
      cnt++;
    } else
      Q.push_back({{l, l + cnt - 1}, temp}), l += cnt, temp = ar[i], cnt = 1;
  }
  Q.pb({{l, l + cnt - 1}, temp});
  range(0, (int)Q.size() - 1) {
    pair<point, int> tmp = Q[j];
    ans = min(ans, tmp.second * (tmp.first.first - 1 + n - tmp.first.second));
  }
  cout << ((ans == 1e12) ? 0 : ans) << endl;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
