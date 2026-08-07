#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct Seg {
    int sz;
    vector<i64> cnt, sum;
    
    Seg(int sz) : sz(sz), cnt(4 * sz + 1, 0), sum(4 * sz + 1, 0) {}
    void update(int p, int l, int r, int pos, i64 val) {
        cnt[p]++;
        sum[p] += val;
        if(l == r) return;
        int mid = (l + r) / 2;
        if(pos <= mid) update(p * 2, l, mid, pos, val);
        else update(p * 2 + 1, mid + 1, r, pos, val);
    }
    void update(int pos, i64 val) { update(1, 0, sz - 1, pos, val); }
    int query(int p, int l, int r, i64 need, const vector<i64> b) {
        if(l == r) {
            i64 val = b[l]; 
            return (need + val - 1) / val; 
        }
        int mid = (l + r) / 2;
        if(sum[p * 2 + 1] >= need) {
            return query(p * 2 + 1, mid + 1, r, need, b);
        } 
        else {
            return cnt[p * 2 + 1] + query(p * 2, l, mid, need - sum[p * 2 + 1], b);
        }
    }
    
    int query(i64 need, const vector<i64>& b) {
        if(sum[1] < need) return 1e9; 
        return query(1, 0, sz - 1, need, b);
    }
};

void solve() {
    cin >> n >> m;
    vector<i64> v(n);
    for(auto &x: v) cin >> x; 
    vector a(n, vector<i64>(m));
    vector<i64> b; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            b.push_back(a[i][j]);
        }
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    Seg tr(b.size());
    ans = m;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            int pos = lower_bound(all(b), a[i][j]) - b.begin();
            tr.update(pos, a[i][j]);
        }
        ans = min(ans, tr.query(v[i], b));
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
