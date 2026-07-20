#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const i64 mod = 998244353;

void solve() {
    int p, q;
    cin >> p >> q;
    vector<int> a(q), b(q);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<int> pw(q);
    pw[0] = 1;
    for(int i = 1; i < q; i++) {
        pw[i] = pw[i - 1] * m;
    }

    int states = pw[q - 1] * m;

    auto encode = [&](const vector<int> &v) {
        int id = 0;
        for(int i = 0; i < q; i++) {
            id += v[i] * pw[i];
        }
        return id;
    };

    vector<bool> valid(states, true);

    for(int id = 0; id < states; id++) {
        int x = id;
        int last = -1;

        for(int i = 0; i < q; i++) {
            int color = x % m;
            x /= m;

            if(i && color == last) {
                valid[id] = false;
                break;
            }

            last = color;
        }
    }

    vector<i64> dp(states);
    dp[encode(a)] = 1;

    for(int row = 1; row < p; row++) {
        for(int pos = 0; pos < q; pos++) {
            int step = pw[pos];
            int block = step * m;

            for(int l = 0; l < states; l += block) {
                for(int offset = 0; offset < step; offset++) {
                    i64 sum = 0;

                    for(int color = 0; color < m; color++) {
                        int id = l + offset + color * step;
                        sum += dp[id];
                    }

                    sum %= mod;

                    for(int color = 0; color < m; color++) {
                        int id = l + offset + color * step;
                        dp[id] = (sum - dp[id] + mod) % mod;
                    }
                }
            }
        }

        for(int id = 0; id < states; id++) {
            if(!valid[id]) dp[id] = 0;
        }
    }

    cout << dp[encode(b)] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}