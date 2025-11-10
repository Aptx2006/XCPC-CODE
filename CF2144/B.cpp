// Problem: B. Maximum Cost Permutation
// Contest: Codeforces - Educational Codeforces Round 182 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2144/problem/B
// StartTime 2025-09-15 22:43:00
// Memory Limit: 256 MB
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

const int MAXN = 2e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
int bb[MAXN];
void solve() {
  cin >> n;
  cnt = 0;
  vector<int> buc(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    buc[ar[i]] = 1;
  }
  cnt = n;
  forrr(n) {
    if (ar[i] == 0) {
      while (buc[cnt] == 1) cnt--;
      ar[i] = cnt--;
    }
  }
  int l = 0, r = 0;
  forrr(n) {
    if (ar[i] != bb[i]) {
      l = i;
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (ar[i] != bb[i]) {
      r = i;
      break;
    }
  }
  if (!l and !r) {
    cout << 0 << endl;
  } else
    cout << r - l + 1 << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  for (int i = 1; i < MAXN; i++) bb[i] = i;
  cin >> times;
  while (times--) solve();
  return 0;
}
