#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
const int N = 1e6 + 5;
i64 xjs[N];
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int q;
    cin >> n >> q;
    vector<i64> a(n), flag(n + 1);
    for(auto &x: a) cin >> x;
    for(int i = 1; i <= n; i++) {
        flag[i] = flag[i - 1] ^ xjs[a[i - 1]];
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(flag[l - 1] == flag[r]) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < N; i++) xjs[i] = rnd();
    for(cin >> T; T--; solve());
    return 0;
}
