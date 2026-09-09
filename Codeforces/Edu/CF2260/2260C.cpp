#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, cnt, ans;

void solve() {
    i64 x, y;
    cin >> x >> y;
    i64 tag = x + y, ans = 0, curx = 0;
    for(int i = 30; i >= 0; i--) {
        if((tag >> i) & 1) {
            i64 tmp = curx | (1 << i);
            if(tmp <= x) {
                curx = tmp;
            }
        }
    }
    cout << tag << ' ' << x - curx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}