#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

i64 qpow(i64 base, i64 mi, i64 res = 1) {
    while(mi) {
        if(mi & 1) {
            res = res * base % mod;
        }
        mi >>= 1;
        base = base * base % mod;
    }
    return res;
}

void solve() {
    cin >> n;
    vector< pair<int, int> > a(n);
    for(auto &[x, y]: a) cin >> x >> y;
    
    vector<int> in(n + 1, 0);
    for(int i = 0; i < n; i++) {
        in[a[i].first]++;
        in[a[i].second]++;
    }
    
    vector<vector<pair<int, int>>> G(n + 1);
    for(int i = 1; i <= n; i++) {
        G[i].reserve(in[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int u = a[i].first, v = a[i].second;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 1) {
            q.push(i);
        }
    }

    vector<bool> vis(n);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(in[u] != 1) continue;
        
        for(auto &[v, id] : G[u]) {
            if(!vis[id]) {
                vis[id] = 1;
                in[u]--;
                in[v]--;
                if(in[v] == 1) {
                    q.push(v);
                }
                break;
            }
        }
    }

    i64 sum = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            sum++;
        }
    }

    i64 res =(n - sum * qpow(2, mod - 2)  % mod + mod) % mod;
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
