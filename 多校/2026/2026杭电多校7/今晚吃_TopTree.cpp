#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<vector<int>> G(n + 5);
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        G[u].push_back(i);
    }
    vector<i64> sz(n + 5, 1), h(n + 5);
    i64 sumh = 0;
    for(int i = n; i >= 1; i--) {
        if(G[i].empty()) {
            continue;
        }
        priority_queue<i64, vector<i64>, greater<i64>> pq1;
        i64 best = 0;
        for(auto v : G[i]) {
            sz[i] += sz[v];
            pq1.push(sz[v]);
            best += sz[v];
        }
        i64 merge = 0;
        while(pq1.size() > 2) {
            i64 a = pq1.top(); 
            pq1.pop();
            i64 b = pq1.top(); 
            pq1.pop();
            merge += a + b;
            pq1.push(a + b);
        }
        sumh += best + merge;

        priority_queue<i64, vector<i64>, greater<i64>> pq2;
        i64 mxh = 0;
        for(auto v: G[i]) {
            pq2.push(h[v]);
            mxh = max(mxh, h[v]);
        }
        bool f = 0;
        while(pq2.size() > 1) {
            i64 a = pq2.top();
            pq2.pop();
            i64 b = pq2.top();
            if(a == b) {
                pq2.pop();
                pq2.push(a + 1);
            }else {
                f = 1;
            }
        }
        i64 tp = pq2.top() + f;
        h[i] = max(mxh + 1, tp);
    }
    cout << h[1] << ' ' << sumh << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
