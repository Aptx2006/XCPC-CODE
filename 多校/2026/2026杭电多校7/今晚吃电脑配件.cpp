#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, ans, cnt;
const i64 mod = 1e9;

struct DSU {
    vector<int> fa, sz;
    // xi = ki * xj + ci
    vector<i128> k, c, val;
    vector<bool> isok;
    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        sz.assign(n + 1, 1);
        k.assign(n + 1, 1);
        c.assign(n + 1, 0);
        val.assign(n + 1, 0);
        isok.assign(n + 1, false);
    }
    int find(int x) {
        if(x == fa[x]) return x;
        int root = find(fa[x]);
        c[x] = k[x] * c[fa[x]] + c[x];
        k[x] = k[x] * k[fa[x]];
        return fa[x] = root;
    }
    bool merge(int x, int y, i128 tag) { 
        int rootx = find(x), rooty = find(y);
        if(rootx == rooty) {
            if(k[x] != k[y]) {
                return c[x] + c[y] == tag;
            } else {
                i128 xv = (tag - c[x] - c[y]) / (k[x] + k[y]);
                if(isok[rootx]) return val[rootx] == xv;
                isok[rootx] = true;
                val[rootx] = xv;
                return true;
            }
        } else {
            if(isok[rootx] and isok[rooty]) {
                i128 vx = k[x] * val[rootx] + c[x];
                i128 vy = k[y] * val[rooty] + c[y];
                if(vx + vy != tag) return false;
                return true;
            }
            if(isok[rootx] and !isok[rooty]) {
                fa[rooty] = rootx;
                c[rooty] = k[y] * (tag - c[x] - c[y]);
                k[rooty] = -k[x] * k[y];
            }else if(!isok[rootx] and isok[rooty]) {
                fa[rootx] = rooty;
                c[rootx] = k[x] * (tag - c[x] - c[y]);
                k[rootx] = -k[x] * k[y];
            }else {
                if(sz[rootx] < sz[rooty]) {
                    fa[rootx] = rooty;
                    c[rootx] = k[x] * (tag - c[x] - c[y]);
                    k[rootx] = -k[x] * k[y];
                    sz[rooty] += sz[rootx];
                } else {
                    fa[rooty] = rootx;
                    c[rooty] = k[y] * (tag - c[x] - c[y]);
                    k[rooty] = -k[x] * k[y];
                    sz[rootx] += sz[rooty];
                }
            }
            return true;
        }
    }
};

void solve() {
    cin >> n >> m;
    cnt = 0;
    DSU dsu(n);
    while(m--) {
        int a, b;
        i64 d;
        cin >> a >> b >> d;
        int i = (a + cnt - 1) % n + 1;
        int j = (b + cnt - 1) % n + 1;
        i128 c = (d + cnt) % mod + 1;
        if(dsu.merge(i, j, 2 * c)) {
            cout << "Yes\n";
            cnt++;
        }else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
