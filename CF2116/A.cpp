// Problem: CF 2116 A
// Contest: Codeforces - Codeforces Round 1028 (Div. 2)
// URL: https://codeforces.com/contest/2116/problem/A
// StartTime 2025-05-31 22:35:46
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  // while (b > 0 and d > 0) {
  // d -= 1;
  // if (d <= 0) break;
  // b -= 1;
  // }
  // if (d <= 0) {
  // c -= b;
  // } else
  // a -= d;
  int b1 = min(a, c), d1 = min(b, d);
  int a1 = b1 - d1;
  if (a1 < 0) {
    cout << "Flower" << endl;
  } else {
    cout << "Gellyfish" << endl;
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
