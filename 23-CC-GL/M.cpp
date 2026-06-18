#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<int> aa = a;
    sort(all(aa));
    int l = aa[n / 2], r = max(*max_element(all(a)), *max_element(all(b)));
    ans = l;

    auto isok = [&](int x) {
        vector<int> ck(n), dp(n + 1);
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur += int(a[i] >= x);
            ck[i] = int(b[i] >= x) - int(a[i] >= x);
            if(dp[i] > 0) dp[i + 1] = dp[i] + ck[i];
            else dp[i + 1] = ck[i];
        }
        return *max_element(all(dp)) + cur >= (n + 1) / 2;
    };

    while(l <= r) {
        int mid = (l + r) / 2;
        if(isok(mid)) {
            l = mid + 1;
            ans = mid;
        }else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(T = 1 ; T--; solve());
    return 0;
}
