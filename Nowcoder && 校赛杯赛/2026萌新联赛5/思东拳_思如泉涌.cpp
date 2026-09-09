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
    sort(all(a), greater<int>());
    i64 ans1 = a[0], ans2 = a[0];
    for(int i = 1; i < n; i++) {
        ans1 += a[i];
        ans2 = max(a[i], ans2 - a[i]);
    }
    cout << ans1 + ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
