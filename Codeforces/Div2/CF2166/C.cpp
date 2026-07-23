// Problem: C. Cyclic Merging
// Contest: Codeforces - Codeforces Round 1064 (Div. 2)
// URL: https://codeforces.com/contest/2166/problem/C
// StartTime 2025-11-16 23:54:14
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define range(s, e) for (int i = s; i <= e; i++)
#define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int& x, int& y, point p) { x = p.first, y = p.second; }
void solve() {
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  for (auto& x : a) {
    cin >> x;
    mx = max(mx, x);
  }
  vector<int> mxpos;
  for (int i = 0; i < n; i++) {
    if (a[i] == mx) mxpos.pb(i);
  }
  m = mxpos.size();
  int sum = 0, s = 0;
  for (int i = 0; i < m; i++) {
    int id = (i + 1) % m;
    int cur = (mxpos[i] + 1) % n, idp = mxpos[id];
    vector<int> b;
    int cc = cur;
    while (cc != idp) {
      b.pb(a[cc]);
      cc = (cc + 1) % n;
    }
    if (!b.empty()) {
      s++;
      int lenb = b.size();
      if (lenb <= 1) continue;
      vector<int> par(lenb, -1);
      stack<int> st;
      for (int i = 0; i < lenb; i++) {
        int k = -1;
        while (!st.empty() and b[st.top()] <= b[i]) {
          k = st.top();
          st.pop();
        }
        if (k != -1) par[k] = i;
        if (!st.empty()) par[i] = st.top();
        st.push(i);
      }
      for (int i = 0; i < lenb; i++) {
        if (par[i] != -1) sum += b[par[i]];
      }
    }
  }
  ans = sum + (s + m - 1) * mx;
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
