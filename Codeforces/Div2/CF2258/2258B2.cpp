#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
/*
k次操作 -> cnt -> can = max(cnt) = 2 ^ k
长度 a 卖出 q 根 d
q * d <= a；
q <= can

q == can???
    a == can * d!!
min(a / d, can - 1) + (a == can*d)
*/
void solve() {
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> mp(m + 1);
    i64 sum = 0;
    int mx = 0;
    for(auto &x: a) {
        mp[x]++;
        sum += x;
        mx = max(mx, x);
    }
    vector<int> suf(m + 2);
    for(int x = m; x >= 1; x--) {
        suf[x] = suf[x + 1] + mp[x];
    }
    i64 can = 2;
    m = 1;
    for(int i = 1; i <= m; i++) {
        i64 ans = 0;
        if(can >= mx) {
            ans = sum;
        } else {
            i64 limit = can - 1;
            for(int d = 1; d <= mx; d++) {
                i64 cur = 0;
                for(i64 j = 1; j <= limit and j * d <= mx; j++) {
                    cur += suf[j * d];
                }
                if(can * d <= mx) {
                    cur += mp[can * d];
                }
                ans = max(ans, cur);
            }
        }
        cout << ans << " \n"[i == m];
        if(can < mx) {
            can *= 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
