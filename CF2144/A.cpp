// Problem: A. Cut the Array
// Contest: Codeforces - Educational Codeforces Round 182 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2144/problem/A
// StartTime 2025-09-15 22:36:03
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

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k, ps[MAXN];
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() {
  cin >> n;
  ps[0] = 0;
  forrr(n) {
    cin >> ar[i];
    ps[i] = ps[i - 1] + ar[i];
  }
  for (int l = 1; l < n - 1; l++) {
    for (int r = l + 1; r < n; r++) {
      int s1 = ps[l] % 3, s2 = (ps[r] - ps[l]) % 3, s3 = (ps[n] - ps[r]) % 3;
      if (s1 == s2 and s2 == s3) {
        cout << l << " " << r << endl;
        return;
      } else if (s1 != s2 and s1 != s3 and s2 != s3) {
        cout << l << " " << r << endl;
        return;
      }
    }
  }
  cout << "0 0" << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
