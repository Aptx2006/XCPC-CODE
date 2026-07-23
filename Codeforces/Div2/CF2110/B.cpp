// Problem: 括号匹配判断
// Contest: Custom Problem
// URL: N/A
// StartTime: 2025-05-24 22:44:49
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Coder:unAptx4869
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bint size_t
#define forrr for (int i = 1; i <= n; i++)

const int MAXN = 1e5, MOD = 1e9 + 7;
int n, t, ar[MAXN], ans, cnt, k;

void solve() {
  string s;
  cin >> s;
  stack<char> st;
  for (int i = 1; i < (int)s.length() - 1; i++) {
    char c = s[i];
    if (c == '(') {
      st.push(c);
    } else {  // c == ')'
      if (st.empty()) {
        cout << "YES\n";
        return;
      }
      st.pop();
    }
  }
  if (st.empty()) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) solve();
  return 0;
}
