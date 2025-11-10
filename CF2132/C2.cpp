// Problem: C2. The Cunning Seller (hard version)
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/C2
// StartTime 2025-08-21 23:04:46
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

#define int i64
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int d[22], dd[22];
void solve() {
  cin >> n >> k;
  if (k >= n) {
    ans = 3 * n;
    cout << ans << endl;
    return;
  }
  vector<int> p(60);
  p[0] = n;
  int sum = n, di = 0;
  int i = 0;
  while (i < 60 and sum > k) {
    if (p[i] < 3) {
      i++;
      continue;
    }
    int u = max(0ll, sum - k);
    u = min((u + 1) / 2, p[i] / 3);
    p[i] -= u * 3;
    p[i + 1] += u;
    di += u * dd[i];
    sum -= 2 * u;
    i++;
  }
  if (sum > k)
    cout << -1 << endl;
  else
    cout << n * 3 + di << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  d[0] = 3;
  auto get = [](int x, int res = 0) {
    res = qpow(3, x + 1) + x * qpow(3, x - 1);
    return res;
  };
  for (int i = 1; i < 22; i++) d[i] = get(i);
  for (int i = 0; i < 22; i++) dd[i] = qpow(3, i);

  cin >> times;
  while (times--) solve();
  return 0;
}
