#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  if (n == 1 && m == 1) {
    cout << "YES\n1\n";
    return 0;
  }

  if (n == 1 || m == 1) {
    cout << "YES\n";
    if (n == 1) {
      vector<int> a(m);
      for (int i = 1; i <= m; i++) {
        if (i % 2 == 1) {
          int j = (i - 1) / 2;
          a[j] = i;
        } else {
          int j = m - i / 2;
          a[j] = i;
        }
      }
      for (int j = 0; j < m; j++) {
        cout << a[j];
        if (j < m - 1) cout << ' ';
      }
      cout << '\n';
    } else {
      vector<int> a(n);
      for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
          int j = (i - 1) / 2;
          a[j] = i;
        } else {
          int j = n - i / 2;
          a[j] = i;
        }
      }
      for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
      }
    }
    return 0;
  }

  if (gcd(n, m) != 1) {
    cout << "NO\n";
    return 0;
  }

  vector<vector<bool>> vis(n, vector<bool>(m, false));
  vector<vector<int>> ans(n, vector<int>(m, 0));
  int x = 0, y = 0;
  ans[x][y] = 1;
  vis[x][y] = true;

  for (int i = 1; i < n * m; i++) {
    int dx = i % n;
    int dy = i % m;
    vector<pair<int, int>> candidates = {{(x + dx) % n, y},
                                         {(x - dx + n) % n, y},
                                         {x, (y + dy) % m},
                                         {x, (y - dy + m) % m}};
    bool found = false;
    for (auto [nx, ny] : candidates) {
      if (nx < 0) nx += n;
      if (ny < 0) ny += m;
      nx %= n;
      ny %= m;
      if (!vis[nx][ny]) {
        x = nx;
        y = ny;
        ans[x][y] = i + 1;
        vis[x][y] = true;
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j];
      if (j < m - 1) {
        cout << ' ';
      } else {
        cout << '\n';
      }
    }
  }

  return 0;
}