// Problem: B. Siga ta Kymata
// Contest: Codeforces - Codeforces Round 1063 (Div. 2)
// URL: https://codeforces.com/contest/2163/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
const int MAXN = 5e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() {
  cin >> n;
  vector<int> p(n);
  for (auto &x : p) cin >> x;
  string s;
  cin >> s;
  int minp = -1, maxp = -1;
  for (int i = 0; i < n; i++) {
    if (p[i] == 1) minp = i;
    if (p[i] == n) maxp = i;
  }
  for (int i = 0; i < n; i++)
    if (s[i] == '1') {
      if (i == 0 or i == n - 1 or i == minp or i == maxp) {
        cout << "-1\n";
        return;
      }
    }

  vector<point> res{
      {1, n}, {1, minp + 1}, {1, maxp + 1}, {minp + 1, n}, {maxp + 1, n}};

  sort(all(res));
  res.resize(unique(all(res)) - res.begin());
  cout << res.size() << endl;
  for (auto [x, y] : res) cout << x << ' ' << y << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
