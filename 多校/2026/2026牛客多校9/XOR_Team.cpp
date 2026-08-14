#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i64> a(2 * n);
    map<i64, int> mp;
    for(auto &x: a) {
        cin >> x;
        mp[x]++;
    }
    sort(all(a));
    i64 ans = 0;
    for(int i = 0; i < 2 * n; i += 2) {
        ans += a[i + 1] - a[i];
    }
 
    int pos = 0, res = n, bad = 0;
    map<i64, pair<i64, int> > mp2;
    for(auto &[x, y]: mp) {
        pos += y;
        bad += y - 1;
        if((pos & 1) and bad > 0) {
            res--;
            ans--;
            mp2[-x] = {y - 1, 1};
        }else {
            bad += 2;
            mp2[-x] = {y, 0};
        }
    }
     
    bad = 0;
    for(auto &[x, y] : mp2) {
        auto &[y1, y2] = y;
        while(y1 >= 2 and res > 1) {
            y1 -= 2;
            y2 += 2;
            res -= 2;
        }
        bad += y2 - y1;
        while(bad < 0 and res > 0) {
            bad += 2;
            ans++;
            res--;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
