// Problem: AT ABC419 F
// Contest: AtCoder - AtCoder Beginner Contest 419
// URL: https://atcoder.jp/contests/abc419/tasks/abc419_f
// StartTime 2025-08-16 20:57:10
// Memory Limit: 1024 MB
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
#define int i64
const int MAXN = 1e5 + 5, MOD = 998244353;
int n, m, t, ar[MAXN], ans, cnt, k;
struct Node {
  int child[26];
  int fail;
  int mask;   // 完整掩码
  int omask;  // 模式掩码
  Node() {
    for (int i = 0; i < 26; i++) child[i] = -1;
    fail = -1;
    mask = 0;
    omask = 0;
  }
};

vector<Node> G;
vector<vector<int>> st;
void insert(string s, int idx) {
  int cur = 0;
  for (char c : s) {
    int id = c - 'a';
    if (G[cur].child[id] == -1) {
      G[cur].child[id] = G.size();
      G.pb(Node());
    }
    cur = G[cur].child[id];
  }
  G[cur].omask |= (1 << idx);
}

void build() {
  queue<int> q;
  G[0].fail = -1;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int c = 0; c < 26; c++) {
      int v = G[u].child[c];
      if (v == -1) continue;

      int f = G[u].fail;
      while (f != -1 and G[f].child[c] == -1) {
        f = G[f].fail;
      }
      if (f == -1) {
        G[v].fail = 0;
      } else {
        G[v].fail = G[f].child[c];
      }
      G[v].mask = G[v].omask | G[G[v].fail].mask;
      q.push(v);
    }
  }
}

void build1() {
  int sz = G.size();
  st.resize(sz, vector<int>(26, -1));

  for (int c = 0; c < 26; c++) {
    if (G[0].child[c] != -1) {
      st[0][c] = G[0].child[c];
    } else {
      st[0][c] = 0;
    }
  }
  vector<int> bfs;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    bfs.pb(u);
    for (int c = 0; c < 26; c++) {
      int v = G[u].child[c];
      if (v != -1) {
        q.push(v);
      }
    }
  }
  for (int i = 1; i < bfs.size(); i++) {
    int u = bfs[i];
    for (int c = 0; c < 26; c++) {
      if (G[u].child[c] != -1) {
        st[u][c] = G[u].child[c];
      } else {
        st[u][c] = st[G[u].fail][c];
      }
    }
  }
}

void solve() {
  cin >> n >> k;
  vector<string> str(n);
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }

  G.clear();
  G.pb(Node());
  for (int i = 0; i < n; i++) {
    insert(str[i], i);
  }
  build();
  build1();

  int sz = G.size();
  int sum = 1 << n;
  vector dp(sz, vector<int>(sum, 0));
  dp[0][0] = 1;
  for (int len = 0; len < k; len++) {
    vector dpp(sz, vector<int>(sum, 0));
    for (int i = 0; i < sz; i++) {
      for (int mask = 0; mask < sum; mask++) {
        if (dp[i][mask] == 0) continue;
        for (int c = 0; c < 26; c++) {
          int ns = st[i][c];
          int nmask = mask | G[ns].mask;
          dpp[ns][nmask] = (dpp[ns][nmask] + dp[i][mask]) % MOD;
        }
      }
    }
    dp = move(dpp);
  }

  int mask = (1 << n) - 1;
  ans = 0;
  for (int i = 0; i < sz; i++) {
    ans = (ans + dp[i][mask]) % MOD;
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
