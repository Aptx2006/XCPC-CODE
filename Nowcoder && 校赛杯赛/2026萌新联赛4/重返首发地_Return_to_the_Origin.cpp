#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct nod {
    int v, x, y;
    bool operator < (const nod &rhs) const{
        if(v != rhs.v) return v > rhs.v;
        if(x != rhs.x) return x > rhs.x;
        return y > rhs.y;
    }
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void solve() {
    cin >> n >> m;
    vector<string> G(n);
    for(auto &x: G) cin >> x;

    vector dp(n, vector<int>(m, 1e9));
    priority_queue<nod> pq;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(G[i][j] == 'P'){
                dp[i][j] = 0;
                pq.push({0, i, j});
            }
        }
    }

    while(!pq.empty()){
        auto [d, x, y] = pq.top();
        pq.pop();
        if(d > dp[x][y]) continue;
        int w = int(G[x][y] == '1');
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i],ny = y + dy[i];
            if(nx >= 0 and nx < n and ny >= 0 and ny < m and G[nx][ny] != '#'){
                if(dp[nx][ny] > dp[x][y] + w){
                    dp[nx][ny] = dp[x][y] + w;
                    pq.push({dp[nx][ny], nx, ny});
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(G[i][j] == '#') {
                cout << -1 << " ";
            } else {
                if(dp[i][j] == 1e9) cout << -1 << " ";
                else cout << dp[i][j] << " ";
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
