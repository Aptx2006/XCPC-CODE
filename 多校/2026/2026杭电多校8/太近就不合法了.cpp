#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

const i64 mod =  998244353;

i64 qpow(i64 base, i64 mi) {
    i64 res = 1;
    while(mi) {
        if(mi & 1) res = res * base % mod;
        base = base * base % mod;
        mi >>= 1;
    }
    return res;
}

const int N = 1e6 + 5;
i64 fact[N + 5], invf[N + 5];
void init() {
    fact[0] = 1;
    for(int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % mod;
    invf[N] = qpow(fact[N], (mod - 2));
    for(int i = N; i >= 1; i--) invf[i - 1] = invf[i] * i % mod;
}

i64 C(int a, int b) {
    if(b < 0 or b > a) return 0;
    return fact[a] * invf[b] % mod * invf[a - b] % mod;
}

struct nod{
    i64 n, x, k;
};
const int B = 999;
vector<int> small[B + 5], big;
vector<nod> qry;
int ID = 0, mxn = 0;

void solve() {
    int q;
    cin >> n >> q;
    mxn = max(mxn, n);
    for(int i = 0; i < q; i++) {
        i64 x, k;
        cin >> x >> k;
        qry.emplace_back(n, x, k);
        if(k <= B) small[k].push_back(ID++);
        else big.push_back(ID++);
    }
}

void xjs() {
    vector<i64> res(ID), dp(mxn + 5);
    for(int i = 1; i <= B; i++) {
        if(small[i].empty()) continue;
        dp[0] = 1;        
        auto get = [&](int v) {
            if(v >= 0) return dp[v];
            return 1ll;
        };
        for(int j = 1; j <= mxn; j++) {
            dp[j] = (dp[j - 1] + get(j - i)) % mod;
        }
        for(auto j : small[i]) {
            auto &[nn, x, k] = qry[j];
            i64 sum = dp[nn];
            i64 dif = get(x - i) * get(nn - x - i + 1) % mod;
            res[j] = (sum - dif + mod) % mod;
        }
    }

    auto calc = [&](int m, int k) -> i64{
        if(m <= 0) return 1;
        i64 sum = 1;                   
        for(i64 i = 1; ; i++) {
            i64 sz = (i - 1) * (k - 1);
            if(m < i + sz) break;
            sum = (sum + C(m - sz, i)) % mod;
        }
        return sum;
    };

    for(int j : big) {
        auto &[nn, x, k] = qry[j];
        i64 sum = calc(nn, k);
        i64 dif = calc(x - k, k) * calc(nn - x - k + 1, k) % mod;
        res[j] = (sum - dif + mod) % mod;
    }

    for(auto &x: res) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(cin >> T; T--; solve());
    xjs();
    return 0;
}
