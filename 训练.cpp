#include <vector>
#include <algorithm>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

i64 qpow(i64 base, i64 mi, i64 res = 1) {
    while(mi) {
        if(mi & 1) {
            res = res * base % mod;
        }
        mi >>= 1;
        base = base * base % mod;
    }
    return res;
}

void solve() {
    cin >> n;
    vector<i64> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    const i64 INF = 2e18; 
    const int MAX_LEN = 62;
    vector<i64> dp(MAX_LEN + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = MAX_LEN; j >= 1; --j) {
            if (b[i] >= dp[j - 1]) {
                dp[j] = min(dp[j], dp[j - 1] + b[i]);
            }
        }
    }

    int ans = 0;
    for (int j = MAX_LEN; j >= 0; --j) {
        if (dp[j] < INF) {
            ans = j;
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
