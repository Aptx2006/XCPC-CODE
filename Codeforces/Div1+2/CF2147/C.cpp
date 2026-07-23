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
  string s;
  cin >> n >> s;

  vector<int> a;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') a.pb(i);
  }

  int m = a.size();
  if (m == 0) {
    cout << "YES\n";
    return;
  }
  map<int, int> mp;
  for (int i = 0; i < m; ++i) mp[a[i]] = i;
  vector<int> dir(m, -1);
  bool f = true;

  for (int j = 0; j < n and f; ++j) {
    if (s[j] == '1') {
      bool L0 = (j > 0 and s[j - 1] == '0');
      bool R0 = (j < n - 1 and s[j + 1] == '0');

      if (L0 and R0) {
        int ll = mp[j - 1], rr = mp[j + 1];

        if (dir[ll] != -1 and dir[rr] != -1) {
          if (dir[ll] == dir[rr]) {
            f = 0;
            break;
          }
        } else if (dir[ll] != -1) {
          dir[rr] = 1 - dir[ll];
        } else if (dir[rr] != -1) {
          dir[ll] = 1 - dir[rr];
        }
      } else if (L0) {
        int ll = mp[j - 1];
        if (dir[ll] == -1) {
          dir[ll] = 0;
        } else if (dir[ll] != 0) {
          f = 0;
          break;
        }
      } else if (R0) {
        int rr = mp[j + 1];
        if (dir[rr] == -1) {
          dir[rr] = 1;
        } else if (dir[rr] != 1) {
          f = 0;
          break;
        }
      }
    }
  }

  for (int j = 1; j < n - 1 and f; ++j) {
    if (s[j] == '1' and s[j - 1] == '0' and s[j + 1] == '0') {
      int ll = mp[j - 1], rr = mp[j + 1];
      if (dir[ll] != -1 && dir[rr] != -1 && dir[ll] == dir[rr]) {
        f = 0;
        break;
      }
    }
  }

  cout << (f ? "YES" : "NO") << "\n";
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
