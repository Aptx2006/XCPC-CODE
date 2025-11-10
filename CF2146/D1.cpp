// Problem: D1. Max Sum OR (Easy Version)
// Contest: Codeforces - Codeforces Round 1052 (Div. 2)
// URL: https://codeforces.com/contest/2146/problem/D1
// StartTime 2025-09-21 23:54:31
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
#define range(s, e) for (int j = s; j <= e; j++)
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

const int N = (1e5 + 10) * 32;
class Trie {
  int son[N][2], idx;
  int sz[N];

 public:
  void clear() {
    son[0][0] = son[0][1] = 0;
    sz[0] = 0;
    idx = 0;
  }
  void insert(int x) {
    int p = 0;
    sz[p]++;
    for (int i = 30; i >= 0; --i) {
      int s = (x >> i) & 1;
      if (!son[p][s]) {
        son[p][s] = ++idx;
        son[idx][0] = son[idx][1] = 0;
        sz[idx] = 0;
      }
      p = son[p][s];
      sz[p]++;
    }
  }
  void del(int x) {
    int p = 0;
    sz[p]--;
    for (int i = 30; i >= 0; --i) {
      int s = (x >> i) & 1;
      p = son[p][s];
      sz[p]--;
    }
  }
  int getmx(int mask) {
    if (!idx || sz[0] == 0) return -1;
    int p = 0, res = 0;
    for (int i = 30; i >= 0; --i) {
      int tag = ((mask >> i) & 1) ^ 1;
      if (son[p][tag] && sz[son[p][tag]] > 0) {
        res |= (1 << i);
        p = son[p][tag];
      } else if (son[p][!tag] && sz[son[p][!tag]] > 0) {
        p = son[p][!tag];
      } else {
        return -1;
      }
    }
    return res ^ mask;
  }
};
Trie trie;

void solve() {
  int l, r;
  cin >> l >> r;
  cout << r * (r + 1) << endl;
  trie.clear();
  n = r - l + 1;
  range(l, r) trie.insert(j);

  vector<int> a;
  for (int i = 0; i < n; ++i) {
    int val = trie.getmx(l + i);
    a.pb(val);
    trie.del(val);
  }

  for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}