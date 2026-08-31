#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i64> a(n, 1), b(n);
    for(auto &x: b) cin >> x;
    map<i64, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        mp[b[i]].push_back(i);
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    i64 lastans = 0;
    if(b[0] != 0) {
        cout << "-1\n";
        return;
    }
    for(int i = 1; i < (int)b.size(); i++) {
        int sz = mp[b[i - 1]].size();
        i64 cur = b[i] - b[i - 1];
        i64 ans = cur / sz;
        if(cur % sz != 0 or ans <= lastans) {
            cout << "-1\n";
            return;
        }
        for(auto &j: mp[b[i - 1]]) {
            a[j] = ans;
        }
        lastans = ans;
    }
    for(auto &j: mp[b.back()]) a[j] = lastans + 1;
    for(auto &x: a) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
