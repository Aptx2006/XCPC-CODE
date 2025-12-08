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
#define range(s,e) for (int j=s;j!=e;(s<e?j++:j--))
#define endl '\n'
#define debug(A) cout << #A << "==" << A << '\n';
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
//#define int long long
const int MAXN = 3e5 + 5, MOD = 1e9 + 7;
int n, m, q, u, v;

void solve() { 
    cin >> n >> m ;
    vector<vector<int>> G(n+1);
    while(m--) {
        cin >> u >> v;
        G[v].pb(u);
    }
    vector<bool> vis(n+1, false); 
    cin >> q;
    while (q--) {
        int op;
        cin >> op >> v;
        if(op == 1) {
            if (!vis[v]) {
                queue<int> q;
                q.push(v);
                vis[v] = true;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int x : G[u]) {
                        if (!vis[x]) {
                            vis[x] = true;
                            q.push(x);
                        }
                    }
                }
            }
        } 
        else {
            cout << (vis[v] ? "Yes" : "No") << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;// cin >> times;
    while (times--) solve();
    return 0;
}
