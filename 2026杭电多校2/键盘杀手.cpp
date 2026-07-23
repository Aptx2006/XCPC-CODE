#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i64> a(n + 2);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<i64> dp1(n + 5), dp2(n + 5, 2e18); 
    for(int i = 1; i <= n; i++) {
        dp1[i] = min(dp1[i - 1] + a[i - 1], dp2[i - 1]);
        dp2[i] = min(dp1[i - 1] + max(a[i - 1], a[i + 1]), dp2[i - 1] + a[i + 1]);
    }
    cout << dp2[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
