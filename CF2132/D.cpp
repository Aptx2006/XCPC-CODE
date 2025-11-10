// Problem: D. From 1 to Infinity
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/D
// StartTime 2025-08-21 23:12:52
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
int dd[20];
// 10 - 99 [ dd[1],dd[2] ) 90
void solve() {
  cin >> n;
  ans = 0;
  auto get = [](int num, int res = 0) {
    if (num == 0) return res;
    int i = 1;
    while (i <= num) {
      int l = num % i;
      int r = num / (i * 10);
      int cur = (num / i) % 10;
      res += r * i * 45;
      res += cur * (l + 1);
      res += cur * (cur - 1) / 2 * i;
      i = i * 10;
      if (i > num) break;
    }
    return res;
  };
  int i = 1;
  while (i <= 18 and n) {
    int sum = 9 * dd[i - 1];
    int len = sum * i;
    if (n >= len) {
      ans += get(dd[i] - 1) - get(dd[i - 1] - 1);
      n -= len;
    } else {
      int ok = n / i;
      int nok = n % i;
      if (ok > 0) {
        ans += get(dd[i - 1] + ok - 1) - get(dd[i - 1] - 1);
      }
      if (nok > 0) {
        string s = to_string(dd[i - 1] + ok);
        // int cur = dd[i - 1] + ok;
        // int ct = 0;
        // while (ct < nok) {
        // ans += cur % 10;
        // cur /= 10;
        // ct++;
        // }
        for (int j = 0; j < nok; j++) ans += s[j] - '0';
      }
      break;
    }
    i++;
  }
  cout << ans << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  for (int i = 0; i < 20; i++) dd[i] = qpow(10, i);

  cin >> times;
  while (times--) solve();
  return 0;
}
