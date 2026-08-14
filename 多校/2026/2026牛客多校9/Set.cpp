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
    i64 mx = 0;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        i64 x;
        cin >> x;
        mx = max(mx, x);
        sum += x & 1;
    }
    i64 ans = (mx + (sum & 1)) / 2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
