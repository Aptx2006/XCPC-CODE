#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct nod{
    i64 l, r;
    int col, dead;
    i64 len(){
        return r - l + 1;
    }
};

void solve() {
    cin >> n >> m;
    vector<nod> a;
    set<pair<i64, int>> st[2];
    priority_queue<tuple<i64, i64, i64>> pq;

    auto add = [&](int col, i64 l, i64 r) {
        if(l > r) return;
        int id = a.size();
        a.push_back({l, r, col, true});
        st[col].insert({l, id});
        pq.push({r - l + 1, col, id});
    };

    for(int i = 0; i < n; i++) {
        i64 l, r;
        cin >> l >> r;
        add(0, l, r);
    }
    for(int i = 0; i < m; i++) {
        i64 l, r;
        cin >> l >> r;
        add(1, l, r);
    }
    vector<i64> ans;
    while(!pq.empty()) {
        auto [len, col, id] = pq.top();
        pq.pop();
        if(!a[id].dead) continue;
        if(a[id].len() != len) continue;
        i64 L = a[id].l, R = a[id].r;
        st[col].erase({a[id].l, id});
        a[id].dead = false;
        ans.push_back(len);
        int ncol = col ^ 1;
        auto it = st[ncol].lower_bound({L, -1});
        if(it != st[ncol].begin()) {
            auto last = prev(it);
            if(a[last->second].r >= L) {
                it = last;
            }
        }
        while(it != st[ncol].end()) {
            int idd = it->second;
            if (a[idd].l > R) break;
            auto nxt = next(it);
            i64 oldL = a[idd].l;
            i64 oldR = a[idd].r;
            st[ncol].erase(it);
            a[idd].dead = false;
            i64 LL = oldL, RR = oldR;
            i64 LR = min(oldR, L - 1), RL = max(oldL, R + 1);
            i64 Llen = 0, Rlen = 0;
            if(LL <= LR) {
                Llen = LR - LL + 1;
            }
            if(RL <= RR) {
                Rlen = RR - RL + 1;
            }
            if(Llen >= Rlen) {
                if(Llen >= 0) {
                    add(ncol, LL, LR);
                }
            }else {
                if(Rlen >= 0) {
                    add(ncol, RL, RR);
                }
            }
            it = nxt;
        }
    }
    sort(all(ans), greater<i64>());
    cout << ans.size() << '\n';
    for(auto &x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
