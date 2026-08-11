#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct DSU{
    vector<int> fa, sz;
    vector<i64> mx;
    DSU(int n) : fa(n + 1), mx(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int u) {
        if(fa[u] == u) return u;
        int root = find(fa[u]);
        mx[u] = max(mx[u], mx[fa[u]]);
        return fa[u] = root;
    }
    void merge(int u, int v, int w) {
        u = find(u), v = find(v);
        if(u == v) return;
        fa[u] = v;
        sz[v] += sz[u];
        mx[u] = max((i64)(w - sz[u] + 1), mx[v]);
    }
};

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

void solve() {
    int q;
    cin >> n >> m >> q;
    auto id = [&](int i, int j) {
        return (i - 1) * m + j;
    };
    DSU dsu(n * m);
    vector<i64> a(n * m + 5);
    i64 ans = 0;
    while(q--) {
        int op, x, y, w;
        cin >> op >> x >> y;
        x ^= ans, y ^= ans;
        if(op - 1) {
            int i = id(x, y);
            dsu.find(i);
            ans = max(0ll, dsu.mx[i] - a[i]);
            cout << ans << '\n';
        }else {
            cin >> w;
            int i = id(x, y);
            a[i] = w;
            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if(nx < 1 or nx > n or ny < 1 or ny > m) continue;
                int j = id(nx, ny);
                if(a[j]) {
                    dsu.merge(j, i, a[i]);
                }
            }
            ans = dsu.sz[dsu.find(i)] - 1;
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
