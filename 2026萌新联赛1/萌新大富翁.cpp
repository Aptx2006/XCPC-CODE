#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct nod {
    i64 op, id = -1, p = 0, toll = 0;
};

void solve() {
    cin >> n >> m;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    vector<nod> e(m);
    for(auto &[op, id, p, t]: e) {
        cin >> op;
        if(op == 1) cin >> p >> t;
    }
    cin >> k;
    vector<i64> d(k);
    for(auto &x: d) cin >> x;

    vector<int> pos(n + 5);
    vector<bool> stop(n + 5), over(n + 5);
    vector< vector<int> > house(n + 5);

    int cur = 0, q = 0;
    cnt = n;

    auto die = [&](int x) {
        a[x] = stop[x] = 0;
        over[x] = 1;
        cnt--;
        for(int y : house[x]) e[y].id = -1;
        house[x].clear();
    };

    while(cnt > 1 and q < k) {
        if(stop[cur]) {
            stop[cur] = 0;
        } else {
            pos[cur] = (pos[cur] + d[q++] % m) % m;
            auto &[op, id, p, toll] = e[pos[cur]];

            if(op == 0) {
                a[cur] += 200;
            } else if(op == 1) {
                if(id == -1 and a[cur] >= p) {
                    a[cur] -= p;
                    id = cur;
                    house[cur].push_back(pos[cur]);
                } else if(id != -1 and id != cur) {
                    if(a[cur] < toll) {
                        a[id] += a[cur];
                        die(cur);
                    } else {
                        a[cur] -= toll;
                        a[id] += toll;
                    }
                }
            } else if(op == 2) {
                a[cur] += 150;
            } else if(op == 3) {
                if(a[cur] < 100) die(cur);
                else a[cur] -= 100;
            } else {
                stop[cur] = 1;
            }
        }
        if(cnt == 1 or q == k) break;
        do {
            cur = (cur + 1) % n;
        } while(over[cur]);
    }

    for(int i = 0; i < n; i++) {
        if(over[i]) {
            cout << "bankrupt 0\n";
        } else {
            cout << a[i] << ' ' << house[i].size() << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}