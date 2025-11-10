// Problem: Rev Equation (NOI-tAUqe ver.) (equation)
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108307/H
// StartTime 2025-08-14 12:03:45
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
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
  string s;
  cin >> s;
  int x = s[0] - '0', y = s[2] - '0';
  if (x == y) {
    cout << "No\n";
    return;
  }
  if (s[1] == '+' or s[1] == '*') {
    cout << "Yes\n";
    return;
  }
  if (s[1] == '-') {
    if (x == 0) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
