#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct DSU {
    vector<int> fa, val;

    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        val.resize(n + 1, 0);
    }

    int find(int x) {
        if(x == fa[x]) return x;
        int root = find(fa[x]);
        val[x] ^= val[fa[x]];
        return fa[x] = root;
    }

    void merge(int x, int y, bool f) {
        int fx = find(x), fy = find(y);
        if(fx != fy) {
            fa[fx] = fy;
            val[fx] = val[x] ^ val[y];
            val[fx] ^= f; // 相同0 相反1
        }
    }
    
    bool get(int u) {
        find(u);
        return val[u] == 1;
    }
};

struct nod {
    int type, id, rank;
};

void solve() {
    int x, y, z;
    cin >> x >> y >> z;

    auto getid1 = [&](int i, int j) -> int{
        return i * y + j;
    };

    auto getid2 = [&](int i, int j) -> int{
        return x * y + i * z + j;
    };

    auto getid3 = [&](int i, int j) -> int{
        return x * y + y * z + i * z + j;
    };

    DSU dsu(x * y + y * z + z * x);
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            string s;
            cin >> s;
            for(int p = 0; p < z; p++) {
                int id1 = getid1(i, j);
                int id2 = getid2(j, p);
                int id3 = getid3(i, p);
                if(s[p] == 'G') {
                    dsu.merge(id1, id2, 0);
                    dsu.merge(id2, id3, 0);
                }else if(s[p] == 'R') {
                    dsu.merge(id2, id3, 0);
                    dsu.merge(id1, id2, 1);
                }else{
                    dsu.merge(id1, id3, 0);
                    dsu.merge(id1, id2, 1);
                }
            }
        }
    }
    vector<int> bucR(x + 5, 0), bucG(y + 5, 0), bucB(z+ 5, 0);

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(dsu.get(getid1(i, j))) bucG[j]++; 
            else bucR[i]++;                                
        }
    }
    for(int j = 0; j < y; j++) {
        for(int p = 0; p < z; p++) {
            if(dsu.get(getid2(j, p))) bucB[p]++;
            else bucG[j]++;
        }
    }
    for(int i = 0; i < x; i++) {
        for(int p = 0; p < z; p++) {
            if(dsu.get(getid3(i, p))) bucB[p]++;
            else bucR[i]++;
        }
    }

    vector<nod> a;
    for(int i = 0; i < x; i++) a.push_back({0, i, bucR[i]});
    for(int i = 0; i < y; i++) a.push_back({1, i, bucG[i]});
    for(int i = 0; i < z; i++) a.push_back({2, i, bucB[i]});

    sort(all(a), [&](auto &o1, auto &o2) {
        if(o1.type != o2.type) {
            if(o1.type == 0 and o2.type == 1) return dsu.get(getid1(o1.id, o2.id));
            if(o1.type == 1 and o2.type == 0) return !dsu.get(getid1(o2.id, o1.id));
            if(o1.type == 1 and o2.type == 2) return dsu.get(getid2(o1.id, o2.id));
            if(o1.type == 2 and o2.type == 1) return !dsu.get(getid2(o2.id, o1.id));
            if(o1.type == 0 and o2.type == 2) return dsu.get(getid3(o1.id, o2.id));
            if(o1.type == 2 and o2.type == 0) return !dsu.get(getid3(o2.id, o1.id));
        }
        if(o1.rank != o2.rank) return o1.rank < o2.rank;
        return o1.id < o2.id;
    });
    vector<int> ansR(x), ansG(y), ansB(z);
    for(int i = 0; i < (int)a.size(); i++) {
        if(a[i].type == 0) ansR[a[i].id] = i;
        else if(a[i].type == 1) ansG[a[i].id] = i;
        else if(a[i].type == 2) ansB[a[i].id] = i;
    }
    for(auto &x: ansR) cout << x + 1 << ' ';
    cout << '\n';
    for(auto &x: ansG) cout << x + 1 << ' ';
    cout << '\n';
    for(auto &x: ansB) cout << x + 1 << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
