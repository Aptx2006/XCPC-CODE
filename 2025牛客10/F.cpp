// Problem: Sensei and Yuuka Going Shopping (yuuka)
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108307/F
// StartTime 2025-08-14 13:59:55
// Memory Limit: 512 MB
// Time Limit: 6000 ms
// Coder:Aptx4869
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

const int MAXN = 1e6 + 5, MOD = 1e9 + 7;
int n, m, t, ans, cnt, k;

vector<int> ar[MAXN];

struct SegmentTree {
  struct Node {
    int l, r;
    int max_val;
    int pos;
    int tag;
  };
  vector<Node> tree;

  void push_up(int p) {
    if (tree[p << 1].max_val >= tree[(p << 1) | 1].max_val) {
      tree[p].max_val = tree[p << 1].max_val;
      tree[p].pos = tree[p << 1].pos;
    } else {
      tree[p].max_val = tree[(p << 1) | 1].max_val;
      tree[p].pos = tree[(p << 1) | 1].pos;
    }
  }

  void push_down(int p) {
    if (tree[p].tag) {
      int tag = tree[p].tag;
      tree[p << 1].max_val += tag;
      tree[p << 1].tag += tag;
      tree[(p << 1) | 1].max_val += tag;
      tree[(p << 1) | 1].tag += tag;
      tree[p].tag = 0;
    }
  }

  void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].tag = 0;
    if (l == r) {
      tree[p].max_val = 0;
      tree[p].pos = l;
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build((p << 1) | 1, mid + 1, r);
    push_up(p);
  }

  void update(int p, int l, int r, int val) {
    if (l <= tree[p].l && tree[p].r <= r) {
      tree[p].max_val += val;
      tree[p].tag += val;
      return;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) update(p << 1, l, r, val);
    if (r > mid) update((p << 1) | 1, l, r, val);
    push_up(p);
  }

  pair<int, int> query(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
      return {tree[p].max_val, tree[p].pos};
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    pair<int, int> res = {0, 0};
    if (l <= mid) {
      auto left_res = query(p << 1, l, r);
      if (left_res.first > res.first) {
        res = left_res;
      }
    }
    if (r > mid) {
      auto right_res = query((p << 1) | 1, l, r);
      if (right_res.first > res.first) {
        res = right_res;
      }
    }
    return res;
  }

  SegmentTree(int n) {
    tree.resize(4 * (n + 1));
    build(1, 1, n);
  }

  void update(int l, int r, int val) {
    if (l > r) return;
    update(1, l, r, val);
  }

  pair<int, int> query(int l, int r) {
    if (l > r) return {0, 0};
    return query(1, l, r);
  }
};
void solve() {
  cin >> n;
  vector<int> a(n + 1), b;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int x = a[i];
    if (ar[x].empty()) {
      b.pb(x);
    }
    ar[x].pb(i);
  }

  vector<vector<point>> add(n + 2), del(n + 2);

  for (int x : b) {
    int cnt = ar[x].size();
    if (cnt < 3) continue;
    int lx = ar[x][0], rx = ar[x][cnt - 1];
    int xx = ar[x][1];
    if (lx + 1 <= n) {
      add[lx + 1].pb({xx + 1, rx});
    }
    if (xx + 1 <= n) {
      del[xx + 1].pb({xx + 1, rx});
    }
  }

  SegmentTree tr(n);
  ans = 0;
  int b1 = 2, b2 = 3;

  range(2, n - 1) {
    for (auto [l, r] : add[j]) tr.update(l, r, 1);
    for (auto [l, r] : del[j]) tr.update(l, r, -1);

    if (j + 1 <= n) {
      auto res = tr.query(j + 1, n);
      if (res.first > ans) {
        ans = res.first;
        b1 = j;
        b2 = res.second;
      }
    }
  }

  cout << ans << endl << b1 << " " << b2 << endl;

  for (int x : b) {
    ar[x].clear();
  }
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int times = 1;
  cin >> times;
  while (times--) solve();
  return 0;
}
