// Problem: C. Monopati
// Contest: Codeforces - Codeforces Round 1063 (Div. 2)
// URL: https://codeforces.com/contest/2163/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int n, m, t, ar[MAXN], a2[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() {
  cin >> n;
  forrr(n) cin >> ar[i];
  forrr(n) cin >> a2[i];
  int m = 2 * n;
  vector<int> pmn(n + 1, MAXN), pmx(n + 1, -1);
  forrr(n) {
    pmn[i] = min(pmn[i - 1], ar[i]);
    pmx[i] = max(pmx[i - 1], ar[i]);
  }
  vector<int> smn(n + 2, MAXN), smx(n + 2, -1);
  for (int i = n; i > 0; i--) {
    smn[i] = min(smn[i + 1], a2[i]);
    smx[i] = max(smx[i + 1], a2[i]);
  }
  vector<int> best(m + 3, MAXN);
  forrr(n) {
    int mn = min(pmn[i], smn[i]);
    int mx = max(pmx[i], smx[i]);
    if (mn >= 1 and mn <= m) {
      best[mn] = min(best[mn], mx);
    }
  }
  vector<int> sbest(m + 4, MAXN);
  sbest[m + 1] = MAXN;
  for (int i = m; i >= 0; i--) {
    sbest[i] = min(best[i], sbest[i + 1]);
  }
  ans = 0;
  forrr(m) {
    int mnx = sbest[i];
    if (mnx <= m) ans += (m - mnx + 1);
  }
  cout << ans << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
