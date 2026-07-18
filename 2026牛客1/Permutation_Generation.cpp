#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, cnt;

void solve() {
    int x;
    cin >> n >> k >> x;
    vector<int> p(n), ans(n);
    for(auto &x: p) cin >> x;
    int pos = 0;
    for(int i = 0; i < n; i++) {
        if(p[i] == x) {
            pos = i;
        }
    }
    int d = (k - pos + n) % n;
    for(int i = 0; i < n; i++) {
        ans[(i + d) % n] = p[i];
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
