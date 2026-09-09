#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> k;
    unordered_map<i64, int> mp;
    i64 sum = 0;
    vector<int> dp(n + 5);
    mp[0] = 0;
    for(int i = 1; i <= n; i++) {
        i64 x;
        cin >> x;
        sum = (sum + x) % k;
        auto it = mp.find(sum);
        dp[i] = max(dp[i], dp[i - 1]);
        if(it != mp.end()) {
            dp[i] = max(dp[i], it->second + 1);
        }
        mp[sum] = max(mp[sum], dp[i]);
    }
    cout << max(dp[n - 1], dp[n]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}