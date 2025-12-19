// Problem: 小月的计数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125084/C
// StartTime 2025-12-19 19:28:43
// Memory Limit: 512 MB
// Time Limit: 8000 ms
// Coder:Aptx4869
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
ui64: 0~1.8e19*/
typedef unsigned long long ull;
typedef unsigned long long ui64;
typedef long long i64;
typedef long long ll;
#define umap unordered_map
#define forrr(A) for (int i = 1; i <= A; i++)
#define range(s, e) for (int j = s; j <= e; j++)
#define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
#define int long long
int MAXN = 1e5 + 5, MOD = 1e9 + 7;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
long long qpow(long long a, long long b, __int128 res = 1) {
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return (long long)res;
}
void solve() {
    long long A, B;
    cin >> A >> B >> MOD;
    vector<int> cA(1e6 + 10);
    vector<int> cB(1e6 + 10);
    for (int i = 0; i <= MOD - 1; i++) {
        cA[qpow(i, A)]++;
    }
    for (int i = 0; i <= MOD - 1; i++) {
        cB[qpow(i, B)]++;
    }
    ll ans = 0;
    for (int i = 0; i <= MOD - 1; i++) {
        ans += cA[i] * cB[i];
    }
    cout << ans << '\n';
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;
    // cin >> times;
    while (times--) solve();
    return 0;
}
