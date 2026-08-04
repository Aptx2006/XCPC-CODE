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
    cin >> n;
    vector<i64> b(n);
    for(auto &x: b) cin >> x;
    const int MAXL = 65;
    const i128 inf = 3e18;
    vector<i128> dp(MAXL + 1, inf);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = MAXL; j >= 1; j--) {
            if(b[i] >= dp[j - 1]) {
                dp[j] = min(dp[j], dp[j - 1] + (i128)b[i]);
            }
        }
    }
    int ans = 0;
    for(int j = MAXL; j >= 0; j--) {
        if(dp[j] < inf) {
            ans = j;
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
