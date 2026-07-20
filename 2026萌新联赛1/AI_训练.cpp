#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    cin >> n;
    ans = 100;
    while(n--) {
        ans = ans * 9 / 10;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}