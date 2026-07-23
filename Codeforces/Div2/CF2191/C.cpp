// Problem: C. Sorting Game
// Contest: Codeforces - Codeforces Round 1073 (Div. 2)
// URL: https://codeforces.com/contest/2191/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
//#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    int c0 = count(all(s), '0');
    vector<int> res;
    for (int i = c0; i < n; i++)
        if (s[i] == '0') res.push_back(i);
    for (int i = 0; i < c0; i++)
        if (s[i] == '1') res.push_back(i);
    sort(all(res));
    if (res.empty())
        cout << "Bob\n";
    else {
        cout << "Alice\n";
        cout << res.size() << '\n';
        for (auto &x : res) cout << x + 1 << ' ';
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
