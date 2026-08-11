#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

using u64 = uint64_t;
using u128 = __uint128_t;

struct Montgomery {
    u64 m, m2, im, l1, l2;
    Montgomery() {}
    Montgomery(u64 m) : m(m) {
        l1 = -(u64)m % m, l2 = -(u128)m % m;
        m2 = m << 1, im = m;
        for (int i = 0; i < 5; i++) {
            im *= 2 - m * im;
        }
    }
    inline u64 operator()(i64 a, i64 b) const {
        u128 c = (u128)a * b;
        return u64(c >> 64) + m - u64((u64)c * im * (u128)m >> 64);
    }
    inline u64 reduce(u64 a) const {
        a = m - u64(a * im * (u128)m >> 64);
        return a >= m ? a - m : a;
    }
    inline u64 trans(i64 a) const {
        return (*this)(a, l2);
    }

    inline u64 mul(i64 a, i64 b) const {
        u64 r = (*this)(trans(a), trans(b));
        return reduce(r);
    }
    u64 pow(u64 a, u64 n) {
        u64 r = l1;
        a = trans(a);
        for (; n; n >>= 1, a = (*this)(a, a)) {
            if (n & 1) r = (*this)(r, a);
        }
        return reduce(r);
    }
}M(10); // 注意预赋值;

bool isprime(i64 n) {
    if (n < 2 || n % 6 % 4 != 1) {
        return (n | 1) == 3;
    }
    u64 s = __builtin_ctzll(n - 1), d = n >> s;
    Montgomery M(n);
    for (i64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        u64 p = M.pow(a, d), i = s;
        while (p != 1 && p != n - 1 && a % n && i--) {
            p = M.mul(p, p);
        }
        if (p != n - 1 && i != s) return false;
    }
    return true;
}
 
i64 rho(i64 n) {
    if (!(n & 1)) return 2;
    i64 x = 0, y = 0, prod = 1;
    auto f = [&](i64 x) -> i64 {
        return M.mul(x, x) + 5; // 这里的种子能被 hack ，如果是在线比赛，请务必 rand 生成
    };
    for (int t = 30, z = 0; t % 64 || gcd(prod, n) == 1; ++t) {
        if (x == y) x = ++z, y = f(x);
        if (i64 q = M.mul(prod, x + n - y)) prod = q;
        x = f(x), y = f(f(y));
    }
    return gcd(prod, n);
}
 
vector<i64> factorize(i64 x) {
    vector<i64> res;
    auto f = [&](auto f, i64 x) {
        if (x == 1) return;
        M = Montgomery(x); // 重设模数
        if (isprime(x)) return res.push_back(x);
        i64 y = rho(x);
        f(f, y), f(f, x / y);
    };
    f(f, x), sort(res.begin(), res.end());
    return res;
}

const int mod = 998244353;
i64 C[65];
void init() {
    C[0] = 1;
    for(i64 i = 1; i <= 60; ++i) {
        i64 a = (i + 1) * (i + 1) * (i + 1) * (i + 1);
        i64 b = i * i * i * i;
        i64 c = (i - 1) * (i - 1) * (i - 1) * (i - 1);
        C[i] = (a - 2 * b + c) % mod;
        if(C[i] < 0) C[i] += mod;
    }
}

void solve() {
    i64 n, m;
    cin >> n >> m;
    if(m % n != 0) {
        cout << "0\n";
        return;
    }
    vector<i64> fac = factorize(m / n);
    ans = 1;
    for(int i = 0; i < fac.size(); ) {
        int j = i;
        while(j < (int)fac.size() and fac[j] == fac[i]) {
            j++;
        }
        ans = (ans * C[j - i]) % mod;
        i = j;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(cin >> T; T--; solve());
    return 0;
}