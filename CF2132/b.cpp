// Problem: B. The Secret Number
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/b
// StartTime 2025-08-21 22:38:07
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

#define int ui64

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
int d[] = {11,
           101,
           1001,
           10001,
           100001,
           1000001,
           10000001,
           100000001,
           1000000001,
           10000000001,
           100000000001,
           1000000000001,
           10000000000001,
           100000000000001,
           1000000000000001,
           10000000000000001,
           100000000000000001,
           1000000000000000001};
void solve() {
  cin >> n;
  vector<int> res;
  for (int i = 0; i < 18; i++) {
    if (d[i] > n) break;
    k = n / d[i];
    if (k * d[i] == n) {
      res.pb(k);
    }
  }
  sort(all(res));
  if (res.size() != 0) {
    cout << res.size() << endl;
    for (auto x : res) cout << x << " ";
    cout << endl;
  } else
    cout << 0 << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
