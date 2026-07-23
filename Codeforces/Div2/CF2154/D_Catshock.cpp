#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
ui64: 0~1.8e19*/
typedef unsigned long long ull;
typedef unsigned long long ui64;
typedef long long i64;
typedef long long ll;
#define umap unordered_map
#define forrr(A) for (int i = 1; i <= A; i++)
#define range(s, e) for (int j = s; j <= e; j++)
#define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
//#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() { 
    cin >> n;
    vector<vector<int>> G(n + 1);
    forrr(n-1){
        int u, v;
        cin >> u >> v;
        G[u].pb(v),G[v].pb(u);
    }
    vector<int> fa(n+1,-1),dis(n+1,-1);
    queue<int> q;
    q.push(1),dis[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;fa[v] = u;
                q.push(v);
            }
        }
    }
    vector<int>tree;
    int d = n;
    while(d!=1){
        tree.pb(d);d=fa[d];
    }
    tree.pb(1);
    reverse(all(tree));  m = tree.size();cnt = 0;
    vector<string> res;
    bool f = 0;int cur= -1;
    auto add = [&](int u) {
        int isok = (dis[u]&1)==(cnt&1);
        if (!f) {
            k=isok;
        } else {
            k=2-isok;
        }
        while(k--){
            res.pb("1");
            cnt++;f = 0;
        }
        res.push_back("2 " + to_string(u));
        f = true;
    };
    function<void(int,int)> dfs = [&](int v,int p){
        for (int w : G[v]) {
            if (w != p) 
                dfs(w, v);
        }
        add(v);
    };
    if (m>1) {
        for (int v : G[tree[0]]) {
            if (v != cur and v != tree[1]) {
                dfs(v, tree[0]);
            }
        }
        res.pb("1");
        cnt++;f = 0;
        cur = tree[0];
    }
    forrr(m-2){
        add(cur);
        for (int v :G[tree[i]]) {
            if (v != cur and v!=tree[i+1]) {
                dfs(v,tree[i]);
            }
        }
        res.pb("1");
        cnt++;f = 0;
        cur = tree[i];
    }
    if (m>1) {
        add(cur);
        for (int v : G[tree.back()]) {
            if (v != tree[m-2] && v != -1) {
                dfs(v, tree.back());
            }
        }
    }
    cout<<res.size()<<endl;
    for (auto x: res) cout<<x<<endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
