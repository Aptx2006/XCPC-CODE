#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

const double eps = 1e-10;
int sgn(double x) {
    return x < -eps ? -1 : x > eps;
}

double f(double p) {
    if(p <= eps) return 1.0 * k;
    if(p >= 1 - eps) return 0.0;
    double q = 1 - p;
    //dbg(q)
    vector<double> dp(n + 5);
    dp[0] = pow(p, n);
    for(int i = 1; i <= n; i++)  dp[i] = dp[i - 1] * (n - i + 1) / i * q / p;
    //dbg(dp[0]) dbg(dp[1]) dbg(dp[2])
    //dbg(dp[0] + dp[1] + dp[2])
    double res = 0;
    for(int i = 0; i < k; i++) {
        res += (1 - dp[0]);
        vector<double> ndp(n + 5);
        ndp[0] = dp[0] * p + dp[1] * p;
        ndp[1] = dp[0] * q + dp[1] * q;
        for(int j = 2; j <= n; j++) {
            ndp[j - 1] += dp[j] * p;
            ndp[j] += dp[j] * q;
        }
        dp = move(ndp);
    }
    return res;
}

double simpson(double l, double r) {
    return (r - l) * (f(l) + f(r) + 4 * f((l + r) / 2)) / 6;
}

double asr(double l, double r, double ans) {
    double mid = (l + r) / 2, a = simpson(l, mid), b = simpson(mid, r);
    if(sgn(a + b - ans) == 0) return ans;
    return asr(l, mid, a) + asr(mid, r, b);
}

void solve() {
    cin >> n >> m >> k;
    double ans = m * asr(0, 1, 0);
    cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
