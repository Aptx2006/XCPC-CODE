#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    int x, y;
    cin >> x >> y >> k;
    int m = min({x, y, (int)sqrt(k * k / 2) + 1});
    cout << "0 0 " << m << ' ' << m << '\n';
    cout << "0 " << m << " " << m << " 0"<< '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
