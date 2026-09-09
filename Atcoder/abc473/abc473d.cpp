#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
const int N = 15, K = 2e5 + 5;
int dp[N][K], tmp[N];

void dfs(int id, i64 val) {
    if(id == n) {
        if(val % n != 0) return;
        tmp[n] = val / n;
        for(int i = 1; i <= n; i++) {
            cout << tmp[i] << " \n"[i == n];
        }
        return;
    }
    for(i64 i = 0; id * i <= val; i++) {
        i64 nval = val - id * i;
        if(!dp[id + 1][nval]) continue;
        tmp[id] = i;
        dfs(id + 1, nval);
    }
}

void solve() {
    cin >> n >> k;
    dp[n + 1][0] = 1;
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = dp[i + 1][j];
            if(j >= i and dp[i][j - i]) {
                dp[i][j] = 1;
            }
        }
    }
    dfs(1, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
