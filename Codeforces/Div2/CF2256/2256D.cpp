#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

const int N = 1e6 + 5;
i64 fact[N], inv[N];

i64 qpow(i64 base, i64 mi, i64 res = 1) {
    while(mi > 0) {
        if(mi & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        mi >>= 1;
    }
    return res;
}

void init(){
    fact[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv[N - 1] = qpow(fact[N - 1], mod - 2);
    for(int i = N - 2; i >= 1; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
};

void solve() {
    cin >> n;
    string s;
    cin >> s;

    int c0 = count(all(s), '0'), c1 = n - c0;
    int k0 = 0, k1 = 0;

    if(c0 == 0 or c1 == 0) {
        cout << "1\n";
        return;
    }
    
    s = '2' + s;
    for(int i = 1; i <= n; i++) {
        if(s[i] != s[i - 1]) {
            if(s[i] == '0') k0++;
            else k1++;
        }
    }
  
    auto C = [](int a, int b) -> i64{
        if(b < 0 or b > a) return 0;
        return fact[a] * inv[b] % mod * inv[a - b] % mod;
    };

    cout << (C(c0 - 1, k0 - 1) * C(c1 - 1, k1 - 1)) % mod << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(cin >> T; T--; solve());
    return 0;
}
