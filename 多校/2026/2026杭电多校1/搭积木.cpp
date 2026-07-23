#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

struct DSU {
    vector<int> fa, p, e, f;

    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n + 1, 1);
        e.resize(n + 1);
        f.resize(n + 1);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) { 
        if (x == y) f[get(x)] = 1;
        x = get(x), y = get(y);
        e[x]++;
        if (x == y) return false;
        if (x < y) swap(x, y); 
        fa[y] = x;
        f[x] |= f[y], p[x] += p[y], e[x] += e[y];
        return true;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
};

struct nod{
    i64 i, a, b;
    bool operator < (const nod& rhs) const{
        i64 l = a * rhs.b;
        i64 r = rhs.a * b;
        if(l != r)  return l < r;
        return i > rhs.i; 
    }
};

void solve() {
    cin >> n;
    vector<i64> a(n + 1), b(n + 1), f(n + 1);
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> f[i];

    DSU dsu(n);
    priority_queue<nod> pq;
    for(int i = 2; i <= n; i++) {
        pq.push({i, a[i], b[i]});
    }
    ans = 0;
    while(!pq.empty()) {
        auto [i, aa, bb] = pq.top();
        pq.pop();
        if(dsu.get(i) != i) continue;
        int fa_ = dsu.get(f[i]);
        if(fa_ == i) continue;
        ans += aa * b[fa_];
        dsu.fa[i] = fa_;
        a[fa_] += aa;
        b[fa_] += bb;
        if(fa_ == 1) continue;
        pq.push({fa_, a[fa_], b[fa_]});
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
