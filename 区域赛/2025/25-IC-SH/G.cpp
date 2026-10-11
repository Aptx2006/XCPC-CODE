#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(A) cout << (#A) << ':' <<  (A) << endl;

const int N = 20;
int n, m;
i64 pw3[N];

void init() {
    
}

struct LB { // Linear Basis
    using i64 = long long;
    const int BASE = 63;
    vector<i64> d, p;
    int cnt, flag;

    LB() {
        d.resize(BASE + 1);
        p.resize(BASE + 1);
        cnt = flag = 0;
    }
    bool insert(i64 val) {
        for (int i = BASE - 1; i >= 0; i--) {
            if (val & (1ll << i)) {
                if (!d[i]) {
                    d[i] = val;
                    return true;
                }
                val ^= d[i];
            }
        }
        flag = 1; //可以异或出0
        return false;
    }
    bool check(i64 val) { // 判断 val 是否能被异或得到
        for (int i = BASE - 1; i >= 0; i--) {
            if (val & (1ll << i)) {
                if (!d[i]) {
                    return false;
                }
                val ^= d[i];
            }
        }
        return true;
    }
    i64 ask_max() {
        i64 res = 0;
        for (int i = BASE - 1; i >= 0; i--) {
            if ((res ^ d[i]) > res) res ^= d[i];
        }
        return res;
    }
};

void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    int cnt = 0, B = 0;
    for(int b = 60; b >= 0; b--) {
        for(int i = 0; i < n; i++) { 
            if((a[i] >> b) & 1ll) {
                cnt++;
            }
        }
        if(cnt) {
            B = b;
            break;
        }
    }
    i64 ans = 0;
    if(cnt & 1) {
        for(auto &x: a) ans ^= x;
        cout << ans << '\n';
        return;
    }
    LB lb;
    for(int k = B; k >= 0; k--) {
        cnt = 0;
        for(int i = 0; i < n; i++) {
            if((a[i] >> k) & 1ll) cnt++;
        }
        if(~cnt & 1) continue;
        for(int i = 0; i < n; i++) {
            if((a[i] >> k) & 1ll) {
                a[i] ^= 1ll << k;
            }
        }
    }
    for(auto &x: a) lb.insert(x);
    cout << lb.ask_max() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
