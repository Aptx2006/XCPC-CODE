#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct nod{
    int val, type;
    const operator < (const nod& rhs) const{
        return val < rhs.val;
    };
};


void solve() {
    cin >> n;
    vector<vector<int>> G(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    auto bfs = [&](int st) {
        vector<int> dp(n + 1, -1), fa(n + 1, -1);
        queue<int> q;
        q.push(st);
        dp[st] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : G[u]) {
                if(dp[v] == -1) {
                    dp[v] = dp[u] + 1;
                    fa[v] = u;
                    q.push(v);
                }
            }
        }
        return pair<vector<int>, vector<int>>{dp, fa};
    };
    
    auto [dp1, fa1] = bfs(1);
    int A = 1;
    for(int i = 1; i <= n; i++) {
        if(dp1[i] > dp1[A]) A = i;
    }
    auto [dpa, faa] = bfs(A);
    int B = 1;
    for(int i = 1; i <= n; i++) {
        if(dpa[i] > dpa[B]) B = i;
    }
    
    vector<int> path;
    int cur = B;
    while(cur != -1) {
        path.push_back(cur);
        cur = faa[cur];
    }
    
    int D = path.size() - 1;
    int c = D / 2;
    int uc = path[c];
    int vc = path[c + 1];
    
    vector<int> mxdp(n + 1, 0);
    auto dfs = [&](auto self, int u, int p, vector<int> &A, int dep = 0) -> void{
        mxdp[u] = 0;
        for(int v : G[u]) {
            if(v != p) {
                self(self, v, u, A, dep + 1);
                mxdp[u] = max(mxdp[u], mxdp[v] + 1);
            }
        }

        int cnt = 0;
        for(int v : G[u]) {
            if(v != p) {
                if(dep + 1 + mxdp[v] == c) {
                    cnt++;
                }
            }
        }
        if(cnt >= 2) {
            A.push_back(dep);
        }
    };
    
    vector<int> A1 = {c}; 
    dfs(dfs, uc, vc, A1);
    // for(int i = c; i >= 1; i--) {
    //     int u = path[i];
    //     int dep = c - i;
    //     int nxt = path[i - 1]; 
    //     int fai = (i == c) ? vc : path[i + 1];
        
    //     bool f = 0;
    //     for(int v : G[u]) {
    //         if(v != fai and v != nxt) {
    //             if(dep + 1 + mxdp[v] == c) {
    //                 f = 1;
    //             }
    //         }
    //     }
    //     if(f) {
    //         A1.push_back(dep);
    //     }
    // }
    
    vector<int> A2 = {c};
    dfs(dfs, vc, uc, A2);
    // for(int i = c + 1; i < D; i++) {
    //     int u = path[i];
    //     int dep = i - (c + 1);
    //     int nxt = path[i + 1];
    //     int fai = (i == c + 1) ? uc : path[i - 1];
        
    //     bool f = 0;
    //     for(int v : G[u]) {
    //         if(v != fai and v != nxt) {
    //             if(dep + 1 + mxdp[v] == c) {
    //                 f = 1;
    //             }
    //         }
    //     }
    //     if(f) {
    //         A2.push_back(dep);
    //     }
    // }
    sort(all(A1));
    A1.erase(unique(all(A1)), A1.end());   
    sort(all(A2));
    A2.erase(unique(all(A2)), A2.end());
    vector<bool> isok(n + 2, 0);
    for(auto x : A1) {
        for(auto y : A2) {
            isok[x + y + 1] = 1;
        }
    }
    
    vector<int> res;
    for(int i = 0; i <= n + 1; i++) {
        if(isok[i]) res.push_back(i);
    }
    
    cout << res.size() << " ";
    for(auto &x: res) {
        cout << x << " ";
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
