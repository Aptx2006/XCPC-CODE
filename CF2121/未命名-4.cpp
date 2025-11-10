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
  int p1;
  cin >> n >> k >> p1;
  vector<int> p(k);
  p[0] = p1;
  for (int i = 1; i < k; ++i) {
    p[i] = p[i - 1] + ((p[i - 1] * 2357 + 137) % 10) + 1;
  }
  sort(p.begin(), p.end());
  int l = 0;
  int r = p.back() - p.front();
  int ans = 0;

  while (l <= r) {
    int mid = l + (r - l) / 2;
    int count = 1;
    int lp = p[0];
    for (int i = 1; i < k; ++i) {
      if (p[i] - lp >= mid) {
        ++count;
        lp = p[i];
      }
    }
    if (count >= n) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  // cin >> times;
  while (times--) solve();
  return 0;
}
