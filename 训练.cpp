#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MAXN = 2e6 + 10; 
vector<int> G[MAXN];      
int dp[MAXN];             

void solve() {
    i64 n;  
    int m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp)); 
    vector<i64> a;     
    vector<pair<i64, i64>> edges; 
    a.push_back(1);
    a.push_back(n + 1);
    for (int i = 0; i < m; ++i) {
        i64 l, r; 
        cin >> l >> r;
        edges.emplace_back(l, r + 1);
        a.push_back(l);
        a.push_back(r + 1);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    auto rank = [&](i64 x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1; 
    };

    for (auto& e : edges) {
        int u = rank(e.first);
        int v = rank(e.second);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    queue<int> q;
    int st = rank(1);    
    int ed = rank(n + 1);
    q.push(st);
    dp[st] = 0;  

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dp[v] == -1) {
                dp[v] = dp[u] + 1;
                q.push(v);
                if (v == ed) {  
                    cout << dp[v] << '\n';
                    return;
                }
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
