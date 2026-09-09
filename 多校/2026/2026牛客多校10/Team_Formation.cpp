#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
int a[30][30], cand[30];
vector<i64> dp;
const i64 inf = 1e18;

i64 dfs(int mask) {
    if(mask == 0) return 0;
    if(dp[mask] != -inf) return dp[mask];
    i64 res = -inf;
    int id = __builtin_ctz(mask);
    int nmask = mask ^ (1 << id);
    int pos[25], cnt = 0;
    for(int i = nmask; i > 0; i &= i - 1) {
        pos[cnt++] = __builtin_ctz(i);
    }

    for(int i = 0; i < cnt; i++) {
        int u = pos[i];
        for(int j = i + 1; j < cnt; j++) {
            int v = pos[j];
            i64 score = a[id][u] + a[id][v] + a[u][v];
            res = max(res, score + dfs(nmask ^ (1 << u) ^ (1 << v)));
        }
    }

    return dp[mask] = res;
}

void solve() {
    cin >> n;
    for(int i = 0; i < 3 * n; i++) {
        for(int j = 0; j < 3 * n; j++) {
            cin >> a[i][j];
        }
    }
    dp.assign(1 << 3 * n, -inf);
    cout << dfs((1 << 3 * n) - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
