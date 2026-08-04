#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

i64 qpow(i64 base, i64 mi, i64 res = 1) {
    while(mi) {
        if(mi & 1) {
            res = res * base % mod;
        }
        mi >>= 1;
        base = base * base % mod;
    }
    return res;
}

void solve() {
    i64 w, l;
    cin >> w >> l;
    i64 res = (qpow(w, l) + l - 1) % mod;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
