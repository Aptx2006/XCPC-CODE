#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct BIT {
    vector<u64> w;
    int n;
    BIT(int n) : n(n), w(n + 1, 0) {}
    void add(int x, u64 v) {
        for(; x <= n; x += x & -x) {
            w[x] += v;
        }
    }
    u64 rangeAsk(int l, int r) {
        auto ask = [&](int x) {
            u64 ans = 0;
            for(; x; x -= x & -x) {
                ans += w[x];
            }
            return ans;
        };
        return ask(r) - ask(l - 1);
    }
};

mt19937_64 rnd(time(0));

struct nod{
    int ty, p;
    i64 x;
    int c, l, r;
};

void solve() {
    int q;
    cin >> n >> q >> k;
    vector<i64> a(n + 1);
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    vector<nod> qry(q);
    vector<i64> vec;
    for(int i = 1; i <= n; i++) vec.push_back(a[i]);
    for(int i = 0; i < q; i++) {
        cin >> qry[i].ty;
        if(qry[i].ty == 1) {
            cin >> qry[i].p >> qry[i].x >> qry[i].c;
            vec.push_back(qry[i].x);
        }else {
            cin >> qry[i].l >> qry[i].r;
        }
    }
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    int sz = vec.size();
    auto get_id = [&](i64 x) {
        return lower_bound(all(vec), x) - vec.begin() + 1;
    };
    vector<u64> B1(k), B2(k);
    u64 sumB1 = 0, sumB2 = 0;
    for(int i = 0; i < k; i++) {
        B1[i] = rnd();
        B2[i] = rnd();
        sumB1 += B1[i];
        sumB2 += B2[i];
    }
    vector<u64> A1(sz + 1), A2(sz + 1);
    for(int i = 1; i <= sz; i++) {
        A1[i] = rnd();
        A2[i] = rnd();
    }
    BIT ta1(n), tab1(n), ta2(n), tab2(n);
    for(int i = 1; i <= n; i++) {
        int id = get_id(a[i]);
        u64 a1 = A1[id], ab1 = a1 * B1[c[i]];
        ta1.add(i, a1);
        tab1.add(i, ab1);
        u64 a2 = A2[id], ab2 = a2 * B2[c[i]];
        ta2.add(i, a2);
        tab2.add(i, ab2);
    }
    for(auto &op : qry) {
        auto &[ty, p, x, cc, l, r] = op;
        if(ty == 1) {
            int id = get_id(a[p]);
            int nid = get_id(x);
            u64 a1 = A1[id], old_ab1 = a1 * B1[c[p]];
            u64 na1 = A1[nid], new_ab1 = na1 * B1[cc];
            ta1.add(p, na1 - a1);
            tab1.add(p, new_ab1 - old_ab1);
            u64 a2 = A2[id], old_ab2 = a2 * B2[c[p]];
            u64 na2 = A2[nid], new_ab2 = na2 * B2[cc];
            ta2.add(p, na2 - a2);
            tab2.add(p, new_ab2 - old_ab2);
            a[p] = x;
            c[p] = cc;
        } else {
            u64 sa1 = ta1.rangeAsk(l, r);
            u64 sab1 = tab1.rangeAsk(l, r);
            bool ok1 = (u64)k * sab1 == sumB1 * sa1;
            u64 sa2 = ta2.rangeAsk(l, r);
            u64 sab2 = tab2.rangeAsk(l, r);
            bool ok2 = (u64)k * sab2 == sumB2 * sa2;
            cout << (ok1 and ok2 ? "YES" : "NO") << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
