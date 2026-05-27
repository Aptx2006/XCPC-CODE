#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

const int INF = 2E9;
int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i32> a(n);
    for(auto &x: a) cin >> x;
    sort(all(a));
    unordered_map<i32, i32> mp;
    for(i32 i = 0; i < n; i++) mp[a[i]] = i;
    ans = 0;
    for(i32 l = 0; l < n; l++) {
        for(i32 mid = l; mid < n; mid++) {
            i32 ar = 2 * a[mid] - a[l];
            if(mp.count(ar)) {
                i32 cur, r= mp[ar];
                if(mid - l >= r - mid) {
                    cur = (r - mid) * 2 + 1;
                }else {
                    cur = (mid - l + 1) * 2;
                }
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
