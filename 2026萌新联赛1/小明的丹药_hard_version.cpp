#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    i64 aa, a, bb, b;
    cin >> aa >> a >> bb >> b;
    //i64 sz = (aa + bb) * 3 + (a + b) * 2 + 5;
    i64 sz = min(aa * 3 + a * 2, bb * 3 + b * 2);
    vector<bool> dp(5005), dp_(5005);
    dp[0] = 1;
    for(int i = 0; i < aa; i++) {
        for(int j = sz; j >= 3; j--) {
            dp[j] = dp[j] or dp[j - 3];
        }
    }
    for(int i = 0; i < a; i++) {
        for(int j = sz; j >= 2; j--) {
            dp[j] = dp[j] or dp[j - 2];
        }
    }
    dp_[0] = 1;
    for(int i = 0; i < bb; i++) {
        for(int j = sz; j >= 3; j--) {
            dp_[j] = dp_[j] or dp_[j - 3];
        }
    }
    for(int i = 0; i < b; i++) {
        for(int j = sz; j >= 2; j--) {
            dp_[j] = dp_[j] or dp_[j - 2];
        }
    }
    for(int i = sz; i >= 0; i--) {
        if(dp_[i] and dp[i]) {
            cout << 2 * i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}