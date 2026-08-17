#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

struct nod {
    i64 cost;
    int id;
    bool operator<(const nod& rhs) const {
        if (cost != rhs.cost) return cost < rhs.cost;
        return id < rhs.id;
    }
};

void solve() {
    cin >> n >> m;
    vector<bool> vis(n + 1);
    vector<i64> a(n + 1);
    vis[n] = 1;
    a[n] = m;
    for(int k = 2; k <= n; k++) {
        i64 cur = n - k + 1,  need = k / 2; 
        vector<nod> b;
        for(int i = cur + 1; i <= n; i++) {
            i64 cost = 0;
            if (vis[i]) {
                cost = a[i] + 1;
            } else {
                cost = 0;
            }
            b.push_back({cost, i});
        }
        sort(all(b));
        i128 sum = 0;
        for(int i = 0; i < need; ++i) {
            sum += b[i].cost;
        }
        if(sum <= m) {
            vector<bool> nvis(n + 1);
            vector<i64> na(n + 1);
            nvis[cur] = 1;
            na[cur] = m - (i64)sum;
            for(int i = 0; i < need; i++) {
                int id = b[i].id;
                nvis[id] = 1;
                na[id] = b[i].cost;
            }
            for(int i = need; i < (int)b.size(); ++i) {
                int id = b[i].id;
                nvis[id] = 1;
                na[id] = 0;
            }
            vis = move(nvis);
            a = move(na);
        } 
    }

    if(vis[1]) {
        cout << a[1] << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
