#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
ui64: 0~1.8e19*/
typedef unsigned long long ull;
typedef unsigned long long ui64;
typedef long long i64;
typedef long long ll;
#define umap unordered_map
#define forrr(A) for(int i = 1; i <= A; i++)
#define range(s,e) for(int j=s;j!=e;(s<e?j++:j--))
#define endl '\n'
#define debug(A) cout << #A << "==" << A << '\n';
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k, p;

int qpow(int base) {
    int res = 1, mi = p - 2, mod = p;
    base %= mod;
    while (mi > 0) {
        if (mi & 1) res = res * base % mod;
        base = base * base % mod;
        mi >>= 1;
    }
    return res;
}
void solve() { 
    cin >> n >> m >> p;
    int invm = qpow(m);
    vector<int> pre(n + 1);
    pre[0] = 1;
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] * invm % p;
    }
    vector<int> psum(n + 2, 0);
    vector<int> psum2(n + 2, 0);
    for(int i = 0; i <= n; i++) {
        psum[i+1] = (psum[i] + pre[i]) % p;
        psum2[i+1] = (psum2[i] + i * pre[i] % p) % p;
    }
    int sumq = 0, sumq2 = 0, sumr = 0;
    for(int i = 1; i <= n; i++) {
        int b = min(i - 1, n - i);
        int q = (psum[b + 1] - psum[0] + p) % p;
        sumq = (sumq + q) % p;
        int sf = (psum2[b + 1] - psum2[0] + p) % p;
        int r = (2 * sf % p + q) % p;
        sumr = (sumr + r) % p;
        int q2 = q * q % p;
        sumq2 = (sumq2 + q2) % p;
    }
    for(int i = 1; i <= n - 1; i++) {
        int maxs = min(i - 1, n - i - 1);
        int bb = 1 + maxs;
        int q = (psum[bb + 1] - psum[1] + p) % p;
        sumq = (sumq + q) % p;
        int sf = (psum2[bb + 1] - psum2[1] + p) % p;
        int r = (2 * sf % p - q + p) % p;
        sumr = (sumr + r) % p;
        int qsq = q * q % p;
        sumq2 = (sumq2 + qsq) % p;
    }
        
    ans = (sumq * sumq % p - sumq2 + p) % p;
    ans = (ans + sumr) % p;
        
    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
