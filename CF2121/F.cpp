// Problem: CF 2121 F
// Contest: Codeforces - Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/F
// StartTime 2025-06-18 00:12:54
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const int MAXN = 2e5 + 5, MOD = 1e9 + 7;
i64 n, m, t, ar[MAXN], p[MAXN], ans, cnt, k;

void solve() {
  cin >> n >> m >> k;
  forrr(n) cin >> ar[i], p[i] = p[i - 1] + ar[i];
  ans = 0;
  int id = 1;
  while (id <= n) {
    if (ar[id] > k) {
      id++;
      continue;
    }
    int r = id;
    while (r <= n and ar[r] <= k) r++;
    r--;
    map<i64, int> mp;
    mp[0] = 1;
    i64 sum = 0;
    range(id, r) {
      i64 cur = p[j] - p[id - 1];
      sum += mp[cur - m];
      mp[cur]++;
    }
    i64 loss = 0;
    int L = id;
    while (L <= r) {
      if (ar[L] == k) {
        L++;
        continue;
      }
      int v = L;
      while (v <= r and ar[v] != k) v++;
      map<i64, int> mp2;
      mp2[0] = 1;
      for (int j = L; j < v; j++) {
        i64 cur = p[j] - p[L - 1];
        loss += mp2[cur - m];
        mp2[cur]++;
      }
      L = v;
    }
    ans += sum - loss;
    id = r + 1;
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
