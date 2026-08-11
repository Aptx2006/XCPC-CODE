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
    bool f = false;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(x == 0 and y == 0) {
            f = true;
        } else {
            int g = __gcd(abs(x), abs(y));
            int nx = x / g,ny = y / g;
            if(nx < 0 or (nx == 0 and ny < 0)) {
                nx = -nx;
                ny = -ny;
            }
            mp[{nx, ny}]++;
        }
    }
    i64 ans = f * (n - 1);
    for(auto &[x, y]: mp) {
        ans += (i64)y * (y - 1) / 2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
