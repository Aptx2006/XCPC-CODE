#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
#define all(A) A.begin(), A.end()
#define dbg(A) cerr << #A << ':' << A << endl;

int n, m, k;

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

struct node{
    i64 val, l, r;
};

void solve(){
    i64 a, b, c;
    cin >> a >> b >> c;
    int q;
    cin >> q;
    i64 A = b - a, B = c - a;
    i64 x, y;
    i64 g = exgcd(A, B, x, y);
    i64 mod = B / g;
    x = (x % mod + mod) % mod;

    auto isok = [&](i64 t, int r, i64 &p, i64 &q) {
        i128 len = (i128)1 << r, s = len * t;
        if(s % g != 0) return false;
        p = (i128)x * ((s / g) % mod) % mod;
        if(s < (i128)A * p) return false;
        q = (s - (i128)A * p) / B;
        return len >= (i128)p + q;
    };

    while(q--) {
        i64 t, p, q;
        p = q = 0;
        cin >> t;
        i64 ans = -1;
        if(a <= t and t <= c) {
            for(int i = 0; i <= 60; i++) {
                if(isok(t - a, i, p, q)) {
                    ans = i;
                    break;
                }
            }
        }
        if(ans == -1) {
            cout << ans << '\n';           
            cout.flush();
            continue;
        }
        cout << ans << '\n';           
        cout.flush();
        i64 curlen = 1ll << ans;
        vector<node> tr;
        tr.push_back({a, -1, -1});
        tr.push_back({b, -1, -1});
        tr.push_back({c, -1, -1});
        vector<pair<i64, i64>> cur;
        if(curlen - p - q != 0) cur.emplace_back(0, curlen - p - q);
        if(p) cur.emplace_back(1, p);
        if(q) cur.emplace_back(2, q);

        for(int i = 0; i < ans; i++) {
            vector< pair<i64, i64> > G[2], nxt;
            for(auto &[x, y]: cur) {
                G[tr[x].val & 1].emplace_back(x, y);
            }
            for(auto &v: G) {
                while(v.size() > 1) {
                    auto [x, y] = v.back();
                    v.pop_back();
                    auto [xx, yy] = v.back();
                    v.pop_back();
                    i64 cnt = min(y, yy);
                    int j = tr.size();
                    i64 nval = tr[x].val + tr[xx].val >> 1;
                    tr.push_back({nval, x, xx});
                    nxt.emplace_back(j, cnt);
                    //dbg(cnt)
                    if(y > cnt) v.emplace_back(x, y - cnt);
                    if(yy > cnt) v.emplace_back(xx, yy - cnt);
                }
                if(v.empty()) continue;
                auto [x, y] = v.back();
                int j = tr.size();
                i64 nval = tr[x].val;
                tr.push_back({nval, x, x});
                nxt.emplace_back(j, y / 2);
            }
            cur = move(nxt);
        }


        int root = cur[0].first;
        for(int i = ans; i >= 1; i--) {
            auto [val, x, y] = tr[root];
            cout << tr[x].val << ' ' << tr[y].val << '\n';
            cout.flush();
            if(i > 1) {
                cin >> t;
                if(t == -1) return;
                if(t == tr[x].val) root = x;
                else root = y;
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
