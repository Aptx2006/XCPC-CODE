// Problem: B. Flipping Binary String
// Contest: Codeforces - Codeforces Round 1081 (Div. 2)
// URL: https://codeforces.com/contest/2192/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
    string s;
    cin >> n >> s;
    cnt = count(all(s), '1');
    if (cnt & 1 and ~(n - cnt) & 1)
        cout << "-1\n";
    else {
        vector<int> res;
        if (~cnt & 1) {
            for (int i = 0; i < n; i++)
                if (s[i] == '1') res.push_back(i + 1);
        } else
            for (int i = 0; i < n; i++)
                if (s[i] == '0') res.push_back(i + 1);
        cout << res.size() << '\n';
        for (auto &x : res) cout << x << ' ';
        if (!res.empty()) cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
