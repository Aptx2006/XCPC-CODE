#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

const int MOD = 998244353;
i64 T, n, m, k, ans, cnt;

i64 qpow(i64 base, i64 mi, i64 res = 1) {
    base %= MOD;
    while(mi > 0) {
        if(mi & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        mi >>= 1;
    }
    return res;
}

struct nod {
    i64 num, den;
    bool operator<(const nod &rhs) const {
        return num * rhs.den < rhs.num * den;
    }
};

void solve() {
    cin >> n;
    vector<i64> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    vector<nod> aa;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            aa.push_back({b[i], b[j]});
        }        
        for(int j = i + 1; j < n; j++) {
            aa.push_back({b[i], b[j]});
        }
    }

    sort(all(aa));
    ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            nod tag = {a[j], a[i]};
            cnt = aa.end() - upper_bound(all(aa), tag);
            ans = (ans + cnt) % MOD;
        }
    }

    ans = (ans * qpow(n *(n - 1) % MOD, MOD - 2)) % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    solve();
}
