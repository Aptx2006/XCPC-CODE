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
  vector<int> p, s;
  int k;
  forrr(3) cin >> t, p.pb(t);
  forrr(3) cin >> t, s.pb(t);
  cin >> k;
  int len = p.size();
  vector<long long> old(len, 0), upd(len, 0);
  long long sum = 0;
  for (int i = 0; i < k; i++) {
    old[k - 1] += p[i] * s[i];
    if (i >= k / 2) {
      upd[k - 1] += p[i];
    }
    sum += p[i] * s[i];
  }
  for (int i = k; i < len; i++) {
    old[i] = old[i - 1] + p[i] * s[i] - p[i - k] * s[i - k];
    p[i] * s[i];
  }
  for (int i = 0, j = k; i < len; i++, j++) {
    upd[j] = upd[j - 1] + p[i] - p[i - k / 2];
  }
  long long mxupd = upd[k - 1] - old[k - 1];
  for (int i = k - 1; i < len; i++) {
    mxupd = max(mxupd, upd[k - 1] - old[k - 1]);
  }
  cout << sum + mxupd;

  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  // cin >> times;
  while (times--) solve();
  return 0;
}
