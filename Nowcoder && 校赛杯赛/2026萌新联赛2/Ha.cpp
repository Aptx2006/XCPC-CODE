#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using pbset = tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update>;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << '\n';

int T = 1, n, m, k, ans, cnt;
const int N = 2000;
i64 a[N + 5][N + 5], dif[N + 5][N + 5], pre[N + 5][N + 5];

void solve() {
    //写累了 想午睡了
    cin >> n;
    dbg(n)
    vector< array<i64, 4> > G(n + 5);
    for(int i = 1; i <= n; i++) {
        i64 u, d, l, r;
        cin >> u >> d >> l >> r;
        G[i] = {u, d, l, r};
        dbg(u)
        dif[u][l]++;
        dif[u][r + 1]--;
        dif[d + 1][l]--;
        dif[d + 1][r + 1]++;
    }
    for(int i = 1; i <= 2000; i++) {
        for(int j = 1; j <= 2000; j++) {
            dif[i][j] += dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1];
        }
    }
    i64 sum = 0;
    
    for(int i = 1; i <= 2000; i++) {
        for(int j = 1; j <= 2000; j++) {
            if(dif[i][j] > 0) sum++;
            a[i][j] = i64(dif[i][j] == 1);
            pre[i][j] = a[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    dbg(sum)
    for(int i = 1; i <= n; i++) {
        auto &[u, d, l, r] = G[i];
        i64 cur = pre[d][r] - pre[u - 1][r] - pre[d][l - 1] + pre[u - 1][l - 1];
        cout << 4000000 - sum + cur << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
