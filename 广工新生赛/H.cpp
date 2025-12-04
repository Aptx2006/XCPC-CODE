#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n+2, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector dp(n+2, vector<int>(3, 0));
    dp[1][1] = a[1];
    dp[2][2] = a[2];
    for(int i = 3; i <= n; i++) {
        dp[i][1] = dp[i-1][2] + a[i];
        dp[i][2] = max(dp[i-2][2], dp[i-2][1]) + a[i];
        //cout << dp[i][1] << ' '<< dp[i][2] << endl;
    }
    cout << max(dp[n][1], dp[n][2]) << '\n';
}