// Problem: A. Souvlaki VS. Kalamaki
// Contest: Codeforces - Codeforces Round 1063 (Div. 2)
// URL: https://codeforces.com/contest/2163/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
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
const int MAXN = 5e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() {
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(all(a));
  for (int i = 1; i < n; i++) {
    if (i & 1 and i != n - 1) {
      swap(a[i], a[i + 1]);
    }
  }
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
