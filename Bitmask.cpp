#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using pii = pair<i64, i64>;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans;

void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    cin >> m;
    int C[60][2][2]{0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 60; j++) {
            i64 u = (a[i] >> j) & 1;
            i64 v = (a[i] >> (j + 1)) & 1;
            C[j][u][v]++;
        }
    }
    vector<i64> st0(60), st1(60);
    for(int i = 0; i < 60; i++) {
        st0[i] = 0;
        st1[i] = 1;
    }
    while(m--) {
        i64 op, x;
        cin >> op >> x;
        for(int i = 0; i < 60; i++) {
            i64 bit = (x >> i) & 1;
            if(op == 1) {
                st0[i] &= bit;
                st1[i] &= bit;
            } else if(op == 2) {
                st0[i] |= bit;
                st1[i] |= bit;
            } else if(op == 3) {
                st0[i] ^= bit;
                st1[i] ^= bit;
            }
        }
        i64 ans = 0;
        for(int i = 0; i < 30; i++) {
            for(int u = 0; u < 2; u++) {
                for(int v = 0; v < 2; v++) {
                    i64 cur = (u == 0 ? st0[i] : st1[i]);
                    i64 cur_ = (v == 0 ? st0[i + 1] : st1[i + 1]);
                    if(cur == 1 and cur_ == 0) {
                        ans += C[i][u][v];
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
