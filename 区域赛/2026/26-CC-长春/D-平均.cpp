#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define all(A) A.begin(), A.end()
#define dbg(A) cerr << #A << ':' << A << endl;
int n, m, k;

using i128 = __int128;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

struct Node{
    i64 val;
    int l, r;
};

void solve(){
    i64 a, b, c;
    if(!(cin >> a >> b >> c)) return;
    int Q;
    cin >> Q;

    // 平移后，初始值为 0, A, B，且 0 < A < B。
    i64 A = b - a, B = c - a;
    i64 x, y;
    i64 g = exgcd(A, B, x, y), mod = B / g;
    x = (x % mod + mod) % mod;

    auto check = [&](i64 t, int r, i64 &p, i64 &q){
        i128 len = (i128)1 << r, s = len * t;
        if(s % g != 0) return false;

        // p 取最小非负解，这时 p + q 也最小。
        p = (i128)x * ((s / g) % mod) % mod;
        i128 rem = s - (i128)A * p;
        if(rem < 0) return false;
        q = rem / B;
        return (i128)p + q <= len;
    };

    while(Q--){
        i64 t, p = 0, q = 0;
        if(!(cin >> t) || t == -1) return;
        int ans = -1;
        if(a <= t && t <= c){
            for(int r = 0; r <= 60; r++){
                if(check(t - a, r, p, q)){
                    ans = r;
                    break;
                }
            }
        }

        cout << ans << endl;
        if(ans <= 0) continue;

        // 每组保存 {节点编号, 出现次数}，无需真的展开 2^ans 个叶子。
        vector<Node> tr = {{a, -1, -1}, {b, -1, -1}, {c, -1, -1}};
        vector<pair<int, i64>> cur;
        i64 len = 1LL << ans;
        if(len - p - q) cur.push_back({0, len - p - q});
        if(p) cur.push_back({1, p});
        if(q) cur.push_back({2, q});

        for(int r = 0; r < ans; r++){
            vector<pair<int, i64>> group[2], nxt;
            for(auto [u, cnt] : cur){
                group[tr[u].val & 1].push_back({u, cnt});
            }

            for(auto &v : group){
                // 同奇偶的不同组尽量互相配对，直到其中一组用完。
                while(v.size() >= 2){
                    auto [u, cu] = v.back();
                    v.pop_back();
                    auto [w, cw] = v.back();
                    v.pop_back();
                    i64 cnt = min(cu, cw);

                    int id = (int)tr.size();
                    tr.push_back({(tr[u].val + tr[w].val) / 2, u, w});
                    nxt.push_back({id, cnt});
                    if(cu > cnt) v.push_back({u, cu - cnt});
                    if(cw > cnt) v.push_back({w, cw - cnt});
                }

                // 若还剩一组，其出现次数一定为偶数，直接自身配对。
                if(!v.empty()){
                    auto [u, cnt] = v.back();
                    int id = (int)tr.size();
                    tr.push_back({tr[u].val, u, u});
                    nxt.push_back({id, cnt / 2});
                }
            }
            cur = move(nxt);
        }

        int rt = cur[0].first;
        for(int r = ans; r >= 1; r--){
            int u = tr[rt].l, v = tr[rt].r;
            cout << tr[u].val << ' ' << tr[v].val << endl;
            if(r > 1){
                if(!(cin >> t) || t == -1) return;
                rt = (t == tr[u].val ? u : v);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1, r;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
