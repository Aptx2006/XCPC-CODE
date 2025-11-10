// Problem: Grammar Test (grammar)
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108307/D
// StartTime 2025-08-14 12:14:27
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
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
#define int i64
const int MAXN = 1e5 + 5, MOD = 998244353;
int n, m, t, ar[MAXN], ans, cnt, k;
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

void solve() {
  cin >> n;
  if ((n - 1) % 6 == 0) {
    cout << 0 << endl;
  } else if ((n - 1) % 3 == 0) {
    k = (n - 1) / 3;
    k = k / 2;
    cout << 2 * qpow(4, k) << endl;
  } else {
    cout << 0 << endl;
  }
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
