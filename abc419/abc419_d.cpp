// Problem: AT ABC419 D
// Contest: AtCoder - AtCoder Beginner Contest 419
// URL: https://atcoder.jp/contests/abc419/tasks/abc419_d
// StartTime 2025-08-16 20:29:40
// Memory Limit: 1024 MB
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
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int len = s.size();
  vector<int> a(len + 1);
  forrr(m) {
    int l, r;
    cin >> l >> r;
    a[l]++, a[r + 1]--;
  }
  forrr(n) {
    a[i] += a[i - 1];
    if (a[i] & 1)
      cout << t[i - 1];
    else
      cout << s[i - 1];
  }
  cout << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  // cin >> times;
  while (times--) solve();
  return 0;
}
