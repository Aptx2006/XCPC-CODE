#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

const int MAXM = 500005;
int mp[MAXM]; 

// 对于 mex = k 进行查询
// 所以每一段就是每次 ai = k 分割出的段
struct qry {
    int l, r, k, id;
    int block;
    bool operator<(const qry& other) const {
        if (block != other.block) return block < other.block;
        return (block & 1) ? (r < other.r) : (r > other.r);
    }
};

struct nod {
    int val, id;
    bool operator<(const nod& other) const {
        if (val != other.val) return val < other.val;
        return id < other.id;
    }
};

void solve() {
    cin >> n >> m;
    vector<int> a(n + 1);
    int lim = min(n + 1, m + 1);
    vector mp1(lim + 1, vector<int>{0});
    for(int i = 1 ; i <= n; i++) {
        cin >> a[i];
        if(a[i] <= lim) {
            mp1[a[i]].emplace_back(i);
        }
    }
    for(int i = 1; i <= lim; i++) mp1[i].emplace_back(n + 1);

    vector<qry> Q;
    int mex = 1, id = 0;    
    while(mex <= lim and mp1[mex].size() > 2) mex++;

    // 增加一条对于 mex = k 的查询
    auto ask = [&](int l, int r, int k) {
        if(r - l + 1 >= k - 1) {
            Q.emplace_back(l, r, k, id++, 0);
        }
    };
    
    for(int k = 1; k <= lim; k++) {
        for(int i = 0; i < (int)mp1[k].size() - 1; i++) {
            ask(mp1[k][i] + 1, mp1[k][i + 1] - 1, k);
        }
    }
    
    int sz = Q.size();
    int B = max(1, (int)(n / sqrt(sz + 1)));
    for(auto &q : Q) {
        q.block = q.l / B;
    }
    
    sort(all(Q));
    
    int L = 1, R = 0;
    int res = 0; // 当前种类数
    
    auto add = [&](int idx) {
        if (mp[a[idx]] == 0) res++;
        mp[a[idx]]++;
    };
    
    auto del = [&](int idx) {
        mp[a[idx]]--;
        if (mp[a[idx]] == 0) res--;
    };
    
    int ans = -1;
    for(auto &q: Q) {
        while(L > q.l) add(--L);
        while(R < q.r) add(++R);
        while(L < q.l) del(L++);
        while(R > q.r) del(R--);
        
        ans = max(ans, res - q.k);
    }
    
    while(L <= R) del(L++);
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T ; T--; solve());
    return 0;
}
