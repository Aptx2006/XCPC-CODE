#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, ans, cnt, st;
const i64 INF = 1e18;

void solve() {
    cin >> n >> m >> st;
    vector<i64> ka(m + 1), ca(m + 1), klim(n + 1);
    for(int i = 1; i <= m; i++) {
        cin >> ka[i] >> ca[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> klim[i];
    }

    vector dp(n + 1, vector<i64>(m + 1, INF));
    dp[st][0] = 0;

    for(int i = 1; i <= m; i++) {
        i64 k = ka[i], c = ca[i];
        vector ndp(n + 1, vector<i64>(m + 1, INF));
        for(int w = 0; w <= i - 1; w++) {
            deque<int> dq;
            int xjs = 1;
            for(int j = 1; j <= n; j++) {
                // for(i64 p = max(1ll, j - k + 1); p <= min(n, j + k - 1); p++) {
                //     ndp[j][w] = min(ndp[j][w], dp[p][w]);
                // }
                i64 L = max(1ll, j - k + 1), R = min(n, j + k - 1);
                while(xjs <= R) {
                    while(!dq.empty() and dp[dq.back()][w] >= dp[xjs][w]) {
                        dq.pop_back();
                    }
                    dq.push_back(xjs);
                    xjs++;
                }
                while(!dq.empty() and dq.front() < L) {
                    dq.pop_front();
                }
                if(!dq.empty()) ndp[j][w] = min(ndp[j][w], dp[dq.front()][w]);
                
                if(j - k >= 1) {
                    ndp[j][w] = min(ndp[j][w], dp[j - k][w] + c);
                }
                if(j + k <= n) {
                    ndp[j][w] = min(ndp[j][w], dp[j + k][w] + c);
                }
            }
        }
        for(int w = 1; w <= i; w++) {
            i64 mnl = INF;
            for(i64 p = 1; p <= min(n, k); p++) {
                mnl = min(mnl, dp[p][w - 1]);
            }
            if(mnl != INF) {
                ndp[1][w] = min(ndp[1][w], mnl + c);
            }
            i64 mnr = INF;
            for(i64 p = max(1ll, n - k + 1); p <= n; p++) {
                mnr = min(mnr, dp[p][w - 1]);
            }
            if(mnr != INF) {
                ndp[n][w] = min(ndp[n][w], mnr + c);
            }
        }
        dp = ndp;
    }

    for(int j = 1; j <= n; j++) {
        int ans = -1;
        for(int w = m; w >= 0; w--) {
            if(dp[j][w] <= klim[j]) {
                ans = w;
                break;
            }
        }
        cout << ans << ' ';
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
