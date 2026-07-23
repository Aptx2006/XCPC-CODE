#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;
const int mod = 998244353, N = 200005;

vector<vector<int>> fact(N); 
i64 pw2[N];          

void init() {
    pw2[0] = 1;
    for(int i = 1; i < N; i++) {
        pw2[i] = (pw2[i - 1] * 2) % mod;
    }
    for(int i = 1; i < N; i++) {
        for(int j = i * 2; j < N; j += i) {
            fact[j].push_back(i);
        }
    }
}

class LB { // Linear Basis
public:
    using i64 = long long;
    const int BASE = 30;
    vector<i64> d, p;
    int sz, cnt, flag;

    LB() {
        d.resize(BASE + 1);
        p.resize(BASE + 1);
        sz = cnt = flag = 0;
    }
    bool insert(i64 val) {
        for (int i = BASE - 1; i >= 0; i--) {
            if (val & (1ll << i)) {
                if (!d[i]) {
                    d[i] = val;
                    sz++;
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
    i64 ask_min() {
        if (flag) return 0; // 特判 0
        for (int i = 0; i <= BASE - 1; i++) {
            if (d[i]) return d[i];
        }
    }
    void rebuild() { // 第k小值独立预处理
        for (int i = BASE - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (d[i] & (1ll << j)) d[i] ^= d[j];
            }
        }
        for (int i = 0; i <= BASE - 1; i++) {
            if (d[i]) p[cnt++] = d[i];
        }
    }
    i64 kthquery(i64 k) { // 查询能被异或得到的第 k 小值, 如不存在则返回 -1
        if (flag) k--; // 特判 0, 如果不需要 0, 直接删去
        if (!k) return 0;
        i64 res = 0;
        if (k >= (1ll << cnt)) return -1;
        for (int i = BASE - 1; i >= 0; i--) {
            if (k & (1LL << i)) res ^= p[i];
        }
        return res;
    }
    void Merge(const LB &b) { // 合并两个线性基
        for (int i = BASE - 1; i >= 0; i--) {
            if (b.d[i]) {
                insert(b.d[i]);
            }
        }
    }
};


void solve() {
    cin >> n;
    vector<int> a(n), mp(n + 1, 0);
    LB lb;
    for(auto &x: a) {
        cin >> x;
        mp[x]++;
        lb.insert(x);
    }
    i64 ans = pw2[n - lb.sz] - 1;
    
    auto add = [&](int x) {
        ans += x;
        if(ans > mod) ans -= mod;
    };

    // 枚举子序列最大值
    for(int mx = 1; mx <= n; mx++) {
        if(!mp[mx]) continue;
        int sum = 0;
        LB lb1;
        for(int &d: fact[mx]) {
            if(mp[d]) {
                sum += mp[d];
                lb1.insert(d);
            }
        }
        // 合法异或和
        i64 base = pw2[sum - lb1.sz];
        // 选奇数个M + 因数异或和为0
        i64 odd = pw2[mp[mx] - 1] * base % mod;
        // 选偶数个M + 因数异或和为M
        i64 even = (pw2[mp[mx] - 1] - 1) * base % mod;
        add(odd), add(even * lb1.check(mx));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(cin >> T ; T--; solve());
    return 0;
}
