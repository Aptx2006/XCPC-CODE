// Problem: B. Multiple Construction
// Contest: Codeforces - Codeforces Global Round 29 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2147/problem/B
// StartTime 2025-09-20 22:40:03
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Coder:Aptx4869
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
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
// #define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() {
  cin >> n;
  cout << n << " ";
  for (int i = n - 1; i >= 1; i--) cout << i << ' ';
  cout << n << " ";
  forrr(n - 1) cout << i << ' ';
  cout << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
