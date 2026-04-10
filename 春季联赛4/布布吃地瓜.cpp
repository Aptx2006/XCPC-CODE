#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;
int D[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void solve() {
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(m));
    vector<vector<pair<int, int>>> mp(n * m + 2);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> G[i][j];
            if(G[i][j] <= n * m + 1) {
                mp[G[i][j]].push_back({i, j});
            }
        }
    }

    auto isTR = [&](int r, int c) {
        if(r == 0 and c == 0) return false;
        if(r == n - 1 and c == m - 1) return false;
        return r == 0 or c == m - 1;
    };

    auto isBL = [&](int r, int c) {
        if(r == 0 and c == 0) return false;
        if(r == n - 1 and c == m - 1) return false;
        return c == 0 or r == n - 1;
    };

    ans = 0;
    vector<vector<int>> vis(n, vector<int>(m, -1));
    while(1) {
        if(ans == G[0][0] or ans == G[n - 1][m - 1]) {
            ans++;
            continue;
        }

        if(ans > n * m + 1 or mp[ans].empty()) {
            break;
        }

        auto& cells = mp[ans];
        bool f = 0;
        
        for(auto &[r, c] : cells) {
            if(vis[r][c] == ans) continue; 
            if(!isTR(r, c)) continue;
            
            queue<pair<int, int>> q;
            q.push({r, c});
            vis[r][c] = ans;
            bool isok = 0;
            
            while(!q.empty()) {
                auto [ur, uc] = q.front();
                q.pop();
                
                if(isBL(ur, uc)) {
                    isok = true;
                    break;             
                }
                
                for(int i = 0; i < 8; i++) {
                    int nr = ur + D[i][0], nc = uc + D[i][1];
                    if(nr >= 0 and nr < n and nc >= 0 and nc < m) {
                        if(G[nr][nc] == ans and vis[nr][nc] != ans) {
                            vis[nr][nc] = ans;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            if(isok) {
                f = true;
                break;
            }
        }

        if(f) {
            ans++;
        } else {
            break;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
