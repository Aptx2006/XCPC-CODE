#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

using nod = tuple<int, int, int>;
vector<vector<int>> G;
vector<int> cur, tag;

void dfs(int id, int sum) {
    if(sum >= ans) return;
    if(id == m) {
        if(cur == tag) {
            ans = min(ans, sum);
        }
        return;
    }
    int mx = 5;
    for(int i = 0; i < n; i++) {
        if(G[id][i] > 0) {
            mx = min(mx, (tag[i] - cur[i]) / G[id][i]);
        }
    }
    for(int i = 0; i <= mx; i++) {
        for(int j = 0; j < n; j++) {
            cur[j] += i * G[id][j];
        }
        dfs(id + 1, sum + i);
        for(int j = 0; j < n; j++) {
            cur[j] -= i * G[id][j];
        }
    }
}

void solve(){
    cin >> n >> m;
    map<string, int> mp;
    G.assign(n + 5, vector<int>(m + 5));
    ans = 1e9;
    cur.resize(n + 5);
    tag.resize(n + 5);
    for(int i = 0; i < n; i++) {
        string s;
        int a;
        cin >> s >> a;
        mp[s] = i;
        tag[i] = a;
    }
    for(int i = 0, t; i < m; i++) {
        cin >> t;
        for(int j = 0; j < t; j++) {
            string s;
            int l;
            cin >> s >> l;
            G[i][mp[s]] = l;
        }
    }
    dfs(0, 0);
    if(ans == 1e9) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
