#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
vector<vector<int>> vis, flag;
vector<int> cur, res;

void dfs(int sum, int mask, int pos) {
    if(vis[sum][mask] <= pos) return;
    vis[sum][mask] = pos;

    if(cur.size() > res.size()) res = cur;
    if(cur.size() == 8) return;

    for(int x = 1; x <= 8; x++) {
        int ns = (sum + x) % 9;
        if(mask >> ns & 1) continue;
        int p = flag[pos][x - 1];
        if(p == n) continue;
        cur.push_back(p);
        dfs(ns, mask | (1 << ns), p + 1);
        cur.pop_back();
    }
}

void solve() {
    cin >> n;
    string s;
    cin >> s;

    flag.assign(n + 1, vector<int>(8, n));
    vis.assign(9, vector<int>(1 << 9, n + 1));
    cur.clear();
    res.clear();

    //vector flag(n + 1, vector<int>(8));
    for(int i = n - 1; i >= 0; i--) {
        flag[i] = flag[i + 1];
        int x = s[i] - '0';
        if(x != 0 and x != 9) {
            flag[i][x - 1] = i;
        }
    }
    //vector vis(9, vector<int>(1 << 9, n + 1));
    dfs(0, 1, 0);

    cout << res.size() << ' ';
    for(auto x: res) cout << x + 1 << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
