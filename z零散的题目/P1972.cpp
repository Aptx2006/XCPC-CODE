#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

class BIT {
    int sz;
    vector<int> tr;
public:
    BIT(int _sz): sz(_sz + 5), tr(_sz + 5) {}
    void add(int i, int d) {
        for(; i <= sz; i += i & -i) tr[i] += d;
    }
    int qry(int i, int res = 0) {
        for(; i > 0; i -= i & -i) res += tr[i];
        return res;
    }
    int range_qry(int l, int r) {
        return qry(r) - qry(l - 1);
    }
};

struct qry {
    int l, id;
};

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    // 值域小，故按右端点存储
    vector<vector<qry>> Q(n + 1);    
    // 增加一条查询
    int id = 0;
    auto ask = [&](int l, int r) {
        if(r >= l) {
            Q[r].emplace_back(l, id++);
        }
    };

    cin >> m;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        ask(l, r);
    }

    BIT bit(n);
    unordered_map<int, int> pos;
    vector<int> aa = a, ans(m);
    sort(all(aa));
    aa.erase(unique(all(aa)), aa.end());
    for(int r = 1; r <= n; r++) {
        int i = lower_bound(all(aa), a[r - 1]) - aa.begin();
        if(pos.count(i)) {
            bit.add(pos[i], -1);
        }
        bit.add(r, 1);
        pos[i] = r;
        for(auto &[l, id]: Q[r]) {
            ans[id] = bit.range_qry(l, r);
        }
    }
    for(auto &x: ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(T = 1 ; T--; solve());
    return 0;
}
