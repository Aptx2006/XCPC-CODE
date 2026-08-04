#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using u128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct LB { // Linear Basis
    using i64 = long long;
    const int BASE = 100;
    vector<u128> d, p;
    vector<i64> s, ps;
    int cnt, flag;

    LB() {
        d.assign(BASE + 1, 0);
        p.assign(BASE + 1, 0);
        s.assign(BASE + 1, 0);
        ps.assign(BASE + 1, 0);
        cnt = flag = 0;
    }
    bool insert(u128 val, i64 sum) {
        for(int i = BASE - 1; i >= 0; i--) {
            if(val & ((u128)1 << i)) {
                if(!d[i]) {
                    d[i] = val;
                    s[i] = sum;
                    return true;
                }
                val ^= d[i];
                sum ^= s[i];
            }
        }
        flag = 1;
        return false;
    }
    bool check(u128 val, i64 &res) {
        for(int i = BASE - 1; i >= 0; i--) {
            if(val & ((u128)1 << i)) {
                if(!d[i]) {
                    return false;
                }
                val ^= d[i];
                res ^= s[i];
            }
        }
        return true;
    }
    i64 ask_max() {
        i64 res = 0;
        return res;
    }
    i64 ask_min() {
        if(flag) return 0;
        for(int i = 0; i <= BASE - 1; i++) {
            if(d[i]) return s[i];
        }
        return 0;
    }
    void rebuild() {
        for(int i = BASE - 1; i >= 0; i--) {
            for(int j = i - 1; j >= 0; j--) {
                if(d[i] & ((u128)1 << j)) {
                    d[i] ^= d[j];
                    s[i] ^= s[j];
                }
            }
        }
        for(int i = 0; i <= BASE - 1; i++) {
            if(d[i]) {
                p[cnt] = d[i];
                ps[cnt] = s[i];
                cnt++;
            }
        }
    }
};

void solve() {
    int c, s, q;
    cin >> k;
    LB lb;
    auto fun = [](vector<int> a) -> u128{
        u128 res = 0;
        for(int x : a) {
            res ^= (u128)1 << (x - 1);
        }
        return res;
    };
    for(int i = 0; i < k; i++) {
        cin >> c >> s;
        vector<int> a(c);
        for(auto &x : a) cin >> x;
        lb.insert(fun(a), s);
    }
    cin >> q;
    while(q--) {
        int d;
        cin >> d;
        vector<int> a(d);
        for(auto &x : a) cin >> x;
        i64 ans = 0;
        if(lb.check(fun(a), ans)) {
            cout << ans << '\n';
        }else {
            cout << "-1\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
