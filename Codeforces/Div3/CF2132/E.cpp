// Problem: E. Arithmetics Competition
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/E
// StartTime 2025-08-21 23:45:54
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

#define int i64
const int MAXN = 2e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  sort(all(a), greater<int>());
  sort(all(b), greater<int>());

  vector<int> aa(n + 1, 0), bb(m + 1, 0);
  forrr(n) aa[i] = a[i - 1] + aa[i - 1];
  forrr(m) bb[i] = b[i - 1] + bb[i - 1];

  while (k--) {
    int x, y, z;
    cin >> x >> y >> z;

    int l = max(0ll, z - y), r = min(z, x);
    if (r < l) {
      cout << 0 << endl;
      continue;
    }
    auto isok = [&](int mid) {
      return aa[mid] + bb[z - mid] < aa[mid + 1] + bb[z - (mid + 1)];
    };
    ans = 0;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (isok(mid)) {
        l = mid + 1;
      } else
        r = mid;
    }
    cout << aa[l] + bb[z - l] << endl;
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
