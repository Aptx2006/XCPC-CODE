#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<pair<int, int> > a(n);
    for(auto &[x, y]: a) cin >> x >> y;

    int dp[m + 1][2]{0};

    for(auto [w, v]: a) {
        for(int j = m; j >= 0; j--) {
            dp[j][1] = max(dp[j][1], dp[j][0] + v);
            if(j >= w) {
                dp[j][1] = max(dp[j][1], dp[j - w][1] + v);
                dp[j][0] = max(dp[j][0], dp[j - w][0] + v);
            }
        }
    }

    cout << max(dp[m][0], dp[m][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
