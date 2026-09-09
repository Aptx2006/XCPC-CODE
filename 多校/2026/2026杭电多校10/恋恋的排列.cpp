#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
vector<int> A = {2, 17, 687};

void solve() {
    cin >> n;
    vector<i64> a(n), pre(n + 1, 0);
    for(auto &x: a) cin >> x;
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    i64 ans = -2e18;
    i64 premx = pre[0];
    i64 mx = premx - pre[0];
    for(int i = 1; i <= n; i++) {
        ans = max(ans, pre[i] + mx);
        premx = max(premx, pre[i]);
        mx = max(mx, premx - pre[i]);
    } 
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
