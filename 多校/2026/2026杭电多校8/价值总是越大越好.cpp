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
i64 fact[N + 5], invf[N + 5], pow2[N + 5];
void init() {
    fact[0] = pow2[0] = 1;
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % mod;
        pow2[i] = pow2[i - 1] * 2 % mod;
    }
    invf[N] = qpow(fact[N], (mod - 2));
    for(int i = N; i >= 1; i--) invf[i - 1] = invf[i] * i % mod;
}

i64 C(int a, int b) {
    if(b < 0 or b > a) return 0;
    return fact[a] * invf[b] % mod * invf[a - b] % mod;
}

void solve() {
    cin >> n;
    int nn = 2 * n;
    vector<int> a(nn);
    for(auto &x: a) cin >> x;
    vector<int> c(nn + 1), b(nn + 1);
    i64 c0 = 0, c1 = 0;
    for(int i = 0; i < nn; i += 2) {
        int x = a[i], y = a[i + 1];
        if(x == 0 and y == 0) {
            c0++;
        }else if(x == 0) {
            c1++;
            c[y] = 1;
        }else if(y == 0) {
            c1++;
            c[x] = 1;
        }else {
            b[x] = 1;
            b[y] = 1;
        }
    }
    i64 sum = c0 + c1, cnt = sum, top = 0;
    for(int v = nn; v >= 1 and cnt > 0; v--) {
        if(b[v]) continue;   
        cnt--;
        if(c[v]) top++;
    }
    i64 ans = pow2[c0] * fact[sum - top] % mod * fact[c0 + top] % mod;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(cin >> T; T--; solve());
    return 0;
}
