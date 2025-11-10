#include <bits/stdc++.h>
using namespace std;
#define int long long
#define more \
  int _;     \
  cin >> _;  \
  while (_--)
#define close                  \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
const int mod = 1e9 + 7, N = 2e5 + 8;
int n, m, ans, cnt, k, l, a[N];

void solve() {
  cin >> n >> m;
  vector<vector<int>> sq(n + 1, vector<int>(m + 1, 0));
  int maxx = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> sq[i][j];
      maxx = max(maxx, sq[i][j]);
    }
  }

  vector<pair<int, int>> Q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (sq[i][j] == maxx) {
        Q.push_back({i, j});
      }
    }
  }

  bool RR = true, CC = true;
  int first_row = Q[0].first, first_col = Q[0].second;

  for (auto& p : Q) {
    if (p.first != first_row) RR = false;
    if (p.second != first_col) CC = false;
  }

  if (RR || CC) {
    cout << maxx - 1 << "\n";
    return;
  }

  vector<int> rows, cols;
  vector<bool> hasr(n + 1, false), hasc(m + 1, false);

  for (auto& p : Q) {
    if (!hasr[p.first]) {
      hasr[p.first] = true;
      rows.push_back(p.first);
    }
    if (!hasc[p.second]) {
      hasc[p.second] = true;
      cols.push_back(p.second);
    }
  }

  bool found = false;
  for (int r : rows) {
    int col = -1;
    bool valid = true;
    for (auto& p : Q) {
      if (p.first == r) continue;
      if (col == -1)
        col = p.second;
      else if (p.second != col) {
        valid = false;
        break;
      }
    }
    if (valid) {
      found = true;
      break;
    }
  }

  cout << (found ? maxx - 1 : maxx) << "\n";
}

signed main() { close more solve(); }