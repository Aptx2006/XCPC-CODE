#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans;

const int N = 1e6 + 10;
struct Trie {
    int ch[N][27], cnt[N], idx = 0;
    int dep[N];
    vector<int> time[N];
    map<char, int> mp;
    void init() {
        i64 id = 0;
        for (char c = 'a'; c <= 'z'; c++) mp[c] = ++id;
        //for (char c = 'A'; c <= 'Z'; c++) mp[c] = ++id;
        //for (char c = '0'; c <= '9'; c++) mp[c] = ++id;
    }
    void insert(string s, int id) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = mp[s[i]];
            if (!ch[u][v]) {
                ch[u][v] = ++idx;
                dep[idx] = dep[u] + 1;
            }
            u = ch[u][v];
            cnt[u]++;
            time[u].push_back(id);
        }
    }
    i64 query(string s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = mp[s[i]];
            if (!ch[u][v]) return 0;
            u = ch[u][v];
        }
        return cnt[u];
    }
    void Clear() {
        for (int i = 0; i <= idx; i++) {
            cnt[i] = 0;
            for (int j = 0; j <= 62; j++) {
                ch[i][j] = 0;
            }
        }
        idx = 0;
    }
} trie;

struct nod {
    int nxtt, dp, id;
    bool operator < (const nod &rhs) const {
        if(rhs.nxtt != nxtt) return nxtt < rhs.nxtt;
        if(rhs.dp != dp) return dp < rhs.dp;
        return id < rhs.id;
    };
};

void solve() {
    cin >> n >> m;
    vector<string> a(n);
    trie.init();
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        trie.insert(a[i], i);
    }
    int id_ = trie.idx, sz = 0, ans = 0;
    vector<int> p(id_ + 5), vis(id_ + 5);
    priority_queue<nod> pq;
    for(int i = 0; i < n; i++) {
        int u = 0;
        for(auto &c: a[i]) {
            u = trie.ch[u][trie.mp[c]];
            if(!vis[u]) {
                vis[u] = 1;
                sz++;
                ans++;
            }
            p[u]++;
            int nxtt = 1e9;
            if(p[u] < trie.time[u].size())  nxtt = trie.time[u][p[u]]; 
            pq.push({nxtt, trie.dep[u], u});
        }
        while(sz > m) {
            auto [nxtt, dp, id] = pq.top();
            pq.pop();
            int need = 1e9;
            if(p[id] < trie.time[id].size())  need = trie.time[id][p[id]];
            if(vis[id] and nxtt == need) {
                vis[id] = 0;
                sz--;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
