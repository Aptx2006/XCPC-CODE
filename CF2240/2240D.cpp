#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    int d;
    cin >> n >> d;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;

    vector<i64> pre(n + 1);
    for(int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    i64 ans = 0;
    for(int i = 0; i < n; i++) {
        int l = (i - d + n) % n;
        int r = (i + d) % n;
        i64 sum = 0;
        if(l <= r) {
            sum = pre[r + 1] - pre[l];
        }else {
            sum = pre[n] - pre[l] + pre[r + 1];
        }
        i64 b = (2ll * d + 1ll) * a[i] - sum;
        if(b > 0) ans += b;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
