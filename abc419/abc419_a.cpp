// Problem: AT ABC419 A
// Contest: AtCoder - AtCoder Beginner Contest 419
// URL: https://atcoder.jp/contests/abc419/tasks/abc419_a
// StartTime 2025-08-16 20:05:24
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
  string s;
  cin >> s;
  if (s == "red") {
    cout << "SSS";
  } else if (s == "blue") {
    cout << "FFF";
  } else if (s == "green") {
    cout << "MMM";
  } else {
    cout << "Unknown";
  }
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  // cin >> times;
  while (times--) solve();
  return 0;
}
