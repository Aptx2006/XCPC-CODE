#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    cin >> n >> m;
    vector< vector<int> > G(n + 5);
    vector<int> in(n + 5);
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        in[v]++;
    }
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) {
            pq.push(-i);
        }
    }
    vector<int> out;
    while(!pq.empty()) {
        int u = -pq.top();
        pq.pop();
        out.push_back(u);
        for(auto &v : G[u]) {
            in[v]--;
            if(in[v] == 0) {
                pq.push(-v);
            }
        }
    }
    if(out.size() != n) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for(auto &x: out) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}