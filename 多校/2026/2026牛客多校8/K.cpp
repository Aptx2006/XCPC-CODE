#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct Edge {
    int to;
    int cap;
    int flow;
    i64 cost;
    int rev;
};

vector<vector<Edge>> adj;

void add(int from, int to, int cap, i64 cost) {
    adj[from].push_back({to, cap, 0, cost, (int)adj[to].size()});
    adj[to].push_back({from, 0, 0, -cost, (int)adj[from].size() - 1});
}

const int inf = 1000000000;

void solve() {
    int a, b;
    cin >> n >> a >> b >> k;
    int N = 2 * a + 2 * b + 2;
    int S = 0, T = N - 1;
    adj.assign(N, vector<Edge>());
    for(int i = 1; i <= a; ++i) {
        int p, c;
        cin >> p >> c;
        add(i, a + i, c, 0);
        if (i > 1) {
            add(a + i, p, inf, 0);
        } else {
            add(a + 1, T, inf, 0);
        }
    }
    for(int i = 1; i <= b; ++i) {
        int p, d;
        cin >> p >> d;
        add(2 * a + i, 2 * a + b + i, d, 0);
        if (i > 1) {
            add(2 * a + b + p, 2 * a + i, inf, 0);
        } else {
            add(S, 2 * a + 1, inf, 0);
        }
    }
    for(int i = 0; i < n; ++i) {
        int x, y;
        i64 w;
        cin >> x >> y >> w;
        add(2 * a + b + y, x, 1, -w);
    }

    vector<i64> h(N, 0);
    vector<bool> vis(N, true);
    queue<int> pq;
    for(int i = 0; i < N; ++i) {
        pq.push(i);
    }
    while(!pq.empty()) {
        int u = pq.front();
        pq.pop();
        vis[u] = false;
        for(auto& e : adj[u]) {
            if (e.cap > 0 and h[e.to] > h[u] + e.cost) {
                h[e.to] = h[u] + e.cost;
                if (!vis[e.to]) {
                    pq.push(e.to);
                    vis[e.to] = true;
                }
            }
        }
    }

    i64 flow = 0, cost = 0;
    vector<i64> dist(N);
    vector<int> p_node(N), p_edge(N);

    while(flow < k) {
        fill(all(dist), 1e18);
        dist[S] = 0;
        priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
        pq.push({0, S});
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for(int i = 0; i < (int)adj[u].size(); ++i) {
                auto& e = adj[u][i];
                if (e.cap - e.flow > 0 and dist[e.to] > dist[u] + e.cost + h[u] - h[e.to]) {
                    dist[e.to] = dist[u] + e.cost + h[u] - h[e.to];
                    p_node[e.to] = u;
                    p_edge[e.to] = i;
                    pq.push({dist[e.to], e.to});
                }
            }
        }
        if (dist[T] == 1e18) break;
        i64 dt = dist[T];
        for(int i = 0; i < N; ++i) {
            h[i] += min(dist[i], dt);
        }
        i64 push = k - flow;
        int curr = T;
        while(curr != S) {
            int p = p_node[curr];
            int idx = p_edge[curr];
            push = min(push, (i64)(adj[p][idx].cap - adj[p][idx].flow));
            curr = p;
        }
        curr = T;
        while(curr != S) {
            int p = p_node[curr];
            int idx = p_edge[curr];
            adj[p][idx].flow += push;
            adj[curr][adj[p][idx].rev].flow -= push;
            cost += push * adj[p][idx].cost;
            curr = p;
        }
        flow += push;
    }

    if (flow < k) {
        cout << -1 << "\n";
    } else {
        cout << -cost << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}