#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
const i64 INF = 1e18;

void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;

    i64 sum = 0, mn = INF;
    cnt = 0;

    for(auto x: a) {
        sum += abs(x);
        mn = min(mn, abs(x));
        if(x < 0) cnt++;
    }
    if((cnt & 1) != ((n - 1) & 1)) {
        sum -= 2 * mn;
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
