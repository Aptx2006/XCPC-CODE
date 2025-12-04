#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define all(A) A.begin(), A.end()
const int N = 2e5 + 5, M = 1e9 + 7;
int n, m;
void solve() {
    cin >> n >> m;
    vector<pair<int,int>> pos(m);
    for(auto &[x, y]: pos) cin >> x >> y;
    sort(all(pos), [](auto o1, auto o2){
        auto [l1, r1] = o1;
        auto [l2, r2] = o2;
        return r1 < r2;
    });
    int last = -1, num = 0;
    for(auto &[l, r]: pos) {
        //cout << l << ' ' << r << endl;
        if(l <= last) {
            continue;
        }
        num++;
        last = r;
    }
    int ans = 0;
    //cout << num << endl;
    while(num) {
        num >>= 1;
        ans ++;
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1 ; cin >> T;
    while(T--) solve();
}