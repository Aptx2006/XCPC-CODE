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
#define int long long

const int MAXN = 505, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;
vector<string> G[MAXN];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m;
        while (m--) {
            string s;
            cin >> s;
            G[i].push_back(s);
        }
    }
    for (int i = 0; i < n; i++) {
        unordered_map<string, int> mp;
        for (auto &s : G[i]) mp[s]++;
        for (int j = i + 1; j < n; j++) {
            cnt = 0;
            for (auto &s : G[j])
                if (mp.count(s)) cnt++;
            if (cnt >= k) ans++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    // cin >> times;
    while (times--) solve();
    return 0;
}
