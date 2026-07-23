#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
// #define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18, N = 510;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    int mp[N][N] = {0};
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if (!mp[a[i] + 201][b[i] + 201]) {
            mp[a[i] + 201][b[i] + 201] = 2;
            q.push({a[i] + 201, b[i] + 201});
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 1; i <= n; i++) {
            int nx = x + a[i], ny = y + b[i];
            if (nx > 0 and ny > 0 and nx <= 402 and ny <= 402 and !mp[nx][ny]) {
                mp[nx][ny] = mp[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << mp[201][201] - 1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
