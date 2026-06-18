#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

const int inf = 1e9;
int T = 1, n, m, k, ans, cnt;
int dp[105][105][2];

struct state {
    int sheep, wolf, step;
};

void solve() {
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    
    auto isok = [&](int s, int w) {
        return s == 0 or w <= s + q;
    };
    
    ans = inf;
    queue<state> Q;
    Q.push({x, y, 0});
    dp[x][y][0] = 0;
    while(!Q.empty()) {
        auto [s_l, w_l, st] = Q.front();
        Q.pop();
        if(!s_l) {
            ans = min(ans, dp[s_l][w_l][st & 1]);
            continue;
        }
        int sheep = s_l, wolf = w_l;
        if(st & 1) {
            sheep = x - s_l;
            wolf = y - w_l;
        }
        for(int i = 0; i <= p; i++) {
            for(int s = 0; s <= min(i, sheep); s++) {
                int w = i - s;
                if(w > wolf) continue;
                if(!isok(sheep - s, wolf - w)) continue;
                if(st & 1) {
                    if(st + 1 < dp[s_l + s][w_l + w][0]) {
                        dp[s_l + s][w_l + w][0] = st + 1;
                        Q.push({s_l + s, w_l + w, st + 1});
                    }
                }else {
                    if(st + 1 < dp[s_l - s][w_l - w][1]) {
                        dp[s_l - s][w_l - w][1] = st + 1;
                        Q.push({s_l - s, w_l - w, st + 1});
                    }
                }
            }
        }
    }
    if(ans == inf) {
        cout << "-1\n";
    }else {
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0x3f, sizeof dp);
    for(; T--; solve());
    return 0;
}
