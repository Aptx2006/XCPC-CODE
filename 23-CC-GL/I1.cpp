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
    int l, k;
};

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    int lim = min(n + 1, m + 1);
    vector mp(lim + 1, vector<int>{0});
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
        if(a[i] <= lim) {
            mp[a[i]].emplace_back(i + 1);
        }
    }
    for(int i = 1; i <= lim; i++) {
        mp[i].emplace_back(n + 1);
    }
    // 值域小，故按右端点存储
    vector<vector<qry>> Q(n + 1);    
    // 增加一条对于 mex = k 的查询
    auto ask = [&](int l, int r, int k) {
        if(r - l + 1 >= k - 1) {
            Q[r].emplace_back(l, k);
        }
    };

    for(int k = 1; k <= lim; k++) {
        for(int i = 0; i < (int)mp[k].size() - 1; i++) {
            ask(mp[k][i] + 1, mp[k][i + 1] - 1, k);
        }
    }

    BIT bit(n);
    unordered_map<int, int> pos;
    int ans = -1;
    vector<int> aa = a;
    sort(all(aa));
    aa.erase(unique(all(aa)), aa.end());
    for(int r = 1; r <= n; r++) {
        int i = lower_bound(all(aa), a[r - 1]) - aa.begin();
        if(pos.count(i)) {
            bit.add(pos[i], -1);
        }
        bit.add(r, 1);
        pos[i] = r;
        for(auto &[l, k]: Q[r]) {
            ans = max(ans, bit.range_qry(l, r) - k);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T ; T--; solve());
    return 0;
}
