#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using pii = pair<i64, i64>;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<pii> a(n);
    for(auto &[x, y]: a) cin >> x >> y;
    for(int i = 1; i < n - 1; i++) {
        auto &[x1, y1] = a[i - 1];
        auto &[x2, y2] = a[i];
        auto &[x3, y3] = a[i + 1];
        if((y2 - y1) *  (x3 - x2) == (y3 - y2) * (x2 - x1)) {
            cout << "STRAIGHT ";
        }else if((y2 - y1) * (x3 - x2) < (y3 - y2) * (x2 - x1)) {
            cout << "LEFT ";
        }else {
            cout << "RIGHT ";
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
