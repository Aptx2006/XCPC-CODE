#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    vector<i64> b(m);
    for(auto &x: b) cin >> x;
    i64 B = a[0] + n - 1;
    i64 A = b[0] + m - 1;
    if(B >= A) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
