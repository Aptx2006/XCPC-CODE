#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    if(n & 1) {
        i64 mn = 1e18;
        for(int i = 0; i < n; i += 2) {
            i64 mx = 1;
            int b = i & 1;
            for(int j = 1; j < i; j += 2) {
                mx = max(mx, a[j] - a[j - 1]);
            }
            for(int j = i + 2; j < n; j += 2) {
                mx = max(mx, a[j] - a[j - 1]);
            }
            mn = min(mn, mx);
        }
        cout << mn << '\n';
    }else {
        i64 mx = 0;
        for(int i = 1; i < n; i+=2) {
            mx = max(mx, a[i] - a[i - 1]);
        }
        cout << mx << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
