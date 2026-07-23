#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
//#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() { 
    cin >> n;
    string s;
    cin >> s;
    vector<int> l(n + 5);
    for(int i = 1; i <= n; i ++) {
        if(s[i - 1] == '1') {
            l[i] = i;
        }else {
            l[i] = l[i - 1];
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(s[i - 1] == '1') break;
        l[i] = l[n];
    }
    ans = 0;
    for(int i = 1; i <= n; i ++) {
        //dbg(l[i])
        if(s[i - 1] == '0') {
            if(i > l[i]) t = i - l[i];
            else t = i + n - l[i];
            ans = max(ans, t);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
