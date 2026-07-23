// Problem: CF 2114 C
// Contest: Codeforces - Codeforces Round  1027 (Div. 3)
// URL: https://codeforces.com/contest/2114/problem/C
// StartTime 2025-05-26 23:30:22
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Coder:unAptx4869
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
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
  cin >> n;
  vector<ll> a(n);
  range(0, n - 1) cin >> a[j];
  cnt = 0;
  ll last = -1e18;
  range(0, n - 1) if (a[j] > last + 1) cnt++, last = a[j];
  cout << cnt << "\n";
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
