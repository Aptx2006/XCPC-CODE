#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    cin >> n >> m;
    vector<string> G(n);
    for(auto &x : G) cin >> x;
    int sx = -1, sy = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (G[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    int sz = n * m * 2;
    vector<int> dis(sz, -1);
    queue<int> q;

    int st = (sx * m + sy) << 1;
    dis[st] = 0;
    q.push(st);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int use = u & 1;
        int cur = u >> 1;
        int x = cur / m;
        int y = cur % m;

        if(G[x][y] == 'T') {
            cout << dis[u] << '\n';
            return;
        }
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 or nx >= n or ny < 0 or ny >= m) {
                continue;
            }
            int nuse = use;
            if(G[nx][ny] == '#') {
                if (use) {
                    continue;
                }
                nuse = 1;
            }
            int nst = ((nx * m + ny) << 1) | nuse;
            if (dis[nst] != -1) {
                continue;
            }
            dis[nst] = dis[u] + 1;
            q.push(nst);
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}