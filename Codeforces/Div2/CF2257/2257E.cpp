#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k;

struct nod{
    i64 need, gain;
    int id, nxt;
    bool operator <(const nod &ths) const{
        return need > ths.need;
    }
};

void solve() {
    i64 x;
    cin >> n >> x;
    vector<vector<i64>> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> m;
        a[i].resize(m);
        b[i].resize(m);
        for(auto &x: a[i]) cin >> x;
        for(auto &x: b[i]) cin >> x;
    }
    vector<int> pos(n);
    const i64 inf = 4e18;
    auto get = [&](int id, int st) -> nod{
        i64 sum = 0, need = 0;
        for(int j = st; j < (int)a[id].size(); j++) {
            need = max(need, a[id][j] - sum);
            sum += b[id][j] - a[id][j];
            if(sum > 0) {
                return {need, sum, id, j + 1};
            }
        }
        return {inf, 0ll, id, st};
    };
    priority_queue<nod> pq;
    for(int i = 0; i < n; i++) {
        nod cur = get(i, 0);
        if(cur.gain > 0) pq.push(cur);
    }
    while(!pq.empty() and pq.top().need <= x) {
        nod u = pq.top();
        pq.pop();
        int i = u.id;
        if (pos[i] != u.nxt) {
            x += u.gain;
            pos[i] = u.nxt;
            nod v = get(i, pos[i]);
            if(v.gain > 0) pq.push(v);
        }
    }
    int ans1 = 0, ans2 = 1;
    for(int i = 0; i < n; i++) {
        i64 money = x;
        int h = pos[i];
        for(int j = pos[i]; j < (int)a[i].size(); j++) {
            if(money < a[i][j]) break;
            money -= a[i][j];
            money += b[i][j];
            h++;
        }
        if(h > ans1) {
            ans1 = h;
            ans2 = i + 1;
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}

