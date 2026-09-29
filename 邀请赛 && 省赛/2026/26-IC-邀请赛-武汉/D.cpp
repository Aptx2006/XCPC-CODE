#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

using P = pair<i64, i64>;
i64 n, m, q, ans;

void solve() {
    cin >> n;
    while(n > 1) {
        i64 nn = 0;
        for(i64 i = 1; i <= 2 * n; i *= 2) {
            for(i64 j = 1; j <= 2 * n / i; j *= 3) {
                i64 cur = i * j;
                if(cur > n and cur < 2 * n) {
                    if(j == 1) cur /= 2;
                    else cur /= 3;
                    nn = max(nn, cur);
                }
            }
        }
        ans++;
        n = nn;
    }
    cout << ans; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
