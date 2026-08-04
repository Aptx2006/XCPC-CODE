#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct nod {
    int sum = 0, kk = 0, mm = 0;
    bool dead = 0;
};

void solve() {
    int q;
    cin >> n >> k >> m >> q;
    unordered_map<string, nod> mp;
    vector<int> res;
    string last;
    cnt = 0;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if(i > 1 and s == last) cnt++;
        else cnt = 1;
        auto &cur = mp[s];
        if(cur.sum == 0) {
            cur.mm = i + m + 1;
        }
        if(cur.kk == 0 and cnt >= k) {
            cur.kk = i + 1;
        }
        bool ok = !cur.dead;
        cur.sum++;
        if(ok and cur.sum <= q and cur.kk and cur.mm and i >= max(cur.kk, cur.mm)) {
            res.push_back(i);
        }
        if(cur.sum == q) cur.dead = true;
        last = s;
    }
    if(res.empty()) {
        cout << "empty\n";
        return;
    }
    for(auto &x: res) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
