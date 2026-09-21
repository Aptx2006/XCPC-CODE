#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m;
i64 ans;
int sx, sy, ex, ey, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool vis[6][6];

void dfs(int x, int y) {
    if(x == ex and y == ey) {
        ans++;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 or nx > n or ny < 1 or ny > m or vis[nx][ny]) continue;
        vis[nx][ny] = true;
        dfs(nx, ny);
        vis[nx][ny] = false;
    }
}

void solve() {
    int k;
    cin >> n >> m >> k;
    cin >> sx >> sy >> ex >> ey;
    while(k--) {
        int x, y;
        cin >> x >> y;
        vis[x][y] = true;
    }
    vis[sx][sy] = true;
    dfs(sx, sy);
    cout << ans << '\n';
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
