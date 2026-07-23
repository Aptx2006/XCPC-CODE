#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(A) (A).begin(), (A).end()
#define dbg(A) cerr << (#A) << "=" << (A) << endl;

i64 T = 1, n, m, ans;

/* 
    x个互质
    (len - x) * 2 + x
    (r - l + 1) * 2 - x
*/

i64 clac(i64 x, const vector<i64>& pri) {
    if(x <= 0) return 0;
    i64 cnt = 0, k = pri.size();
    for(i64 i = 0; i < (1ll << k); i++) {
        i64 pro = 1, st = 0;
        for(i64 j = 0; j < k; j++) {
            if((i >> j) & 1) {
                pro *= pri[j];
                st++;
            }
        }
        if(st & 1) {
            cnt -= x / pro;
        } else {
            cnt += x / pro;
        }
    }
    return cnt;
}

void solve() {
    i64 l, r; 
    cin >> l >> r >> n;

    vector<i64> pri;
    i64 nn = n;
    for(i64 i = 2; i * i <= nn; i++) {
        if(nn % i == 0) {
            pri.push_back(i);
            while(nn % i == 0) nn /= i;
        }
    }
    if(nn > 1) pri.push_back(nn);

    ans = clac(r, pri) - clac(l - 1, pri);
    ans = (r - l + 1) * 2 - ans;

    i64 dp[105];
    dp[0] = 0;
    for(i64 i = 1; i <= min(n - 1, 100ll); i++) {
        i64 u = n - i;
        i64 res = __gcd(u, n);
        for(i64 d = 1; d < i; d++) {
            i64 cand = gcd(u, n - (i - d)) + dp[i - d];
            if(cand < res) res = cand;
        }
        dp[i] = res;
    }
    for(i64 i = max(l, n - 100ll); i <= r; i++) {
        i64 g = __gcd(i, n);
        if(g == 1) continue;
        if(dp[n - i] > 2) ans +=  dp[n - i] - 2;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
