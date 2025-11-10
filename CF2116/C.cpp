// Problem: CF 2116 C
// Contest: Codeforces - Codeforces Round 1028 (Div. 2)
// URL: https://codeforces.com/contest/2116/problem/C
// StartTime 2025-05-31 23:14:38
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

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, a[MAXN], ans, cnt, k;

void solve() {
  cin >> n;
  forrr(n) cin >> a[i];
  int g = a[1];
  forrr(n) g = gcd(g, a[i]);
  bool f = 1;
  forrr(n) if (a[i] != g) {
    f = 0;
    break;
  }
  if (f) {
    cout << "0\n";
    return;
  }
  vector<int> b(n + 1);
  forrr(n) { b[i] = a[i] / g; }
  cnt = 0;
  forrr(n) if (b[i] == 1) cnt++;
  if (cnt > 0) {
    cout << n - cnt << endl;
    return;
  }
  int maxb = *max_element(b.begin(), b.end());
  vector<int> dp(maxb + 5, 1e9);
  forrr(n) {
    if (b[i] <= maxb) {
      dp[b[i]] = min(dp[b[i]], 1);
    }
  }
  forrr(n) {
    vector<int> tdp = dp;
    for (int x = 1; x <= maxb; x++) {
      if (dp[x] < 1e9) {
        int y = gcd(x, b[i]);
        if (y <= maxb) {
          if (tdp[y] > dp[x] + 1) {
            tdp[y] = dp[x] + 1;
          }
        }
      }
    }
    dp = tdp;
  }
  cout << dp[1] + n - 2 << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
