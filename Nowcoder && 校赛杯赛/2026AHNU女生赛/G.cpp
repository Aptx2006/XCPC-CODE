#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m;
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};

void solve() {
    cin >> n >> m;
    vector<string> G(n), ans(n, string(m, 'E'));
    for(auto &x: G) cin >> x;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == '1') {
                ans[i][j] = 'B';
                continue;
            }
            int cnt = 0;
            for(int d = 0; d < 8; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if(ni >= 0 and ni < n and nj >= 0 and nj < m) {
                    if(G[ni][nj] == '1') cnt++;
                }
            }
            if(cnt) ans[i][j] = '0' + cnt;
        }
    }
    for(auto &x: ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
