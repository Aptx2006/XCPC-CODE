#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> k;
    vector<i64> a(n), pre(2 * n + 5);
    for(auto &x: a) cin >> x;
    for(int i = 0; i < n; i++) {
        a.push_back(a[i]);
    }
    for(int i = 1; i <= 2 * n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    i64 ans = -1e18, ansi = 0;
    for(int i = k; i <= 2 * n; i++) {
        if(pre[i] - pre[i - k] > ans) {
            ans = pre[i] - pre[i - k];
            ansi = i - k + 1;
        }
        //ans = max(pre[i] - pre[i - k], ans);
    }
    cout << ans << '\n' << ansi << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
