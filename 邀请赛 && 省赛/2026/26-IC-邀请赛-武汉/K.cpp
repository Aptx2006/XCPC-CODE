#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

using P = pair<i64, i64>;

const int N = 3e5 + 5;
const i64 INF = 4e18;

struct Edge {
    int v;
    i64 w, c;
};

i64 n, m, q, ans;
vector<Edge> G[N];

void solve() {
    cin >> n;
    vector<int> s(n + 1);
    vector<i64> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> fir(N), lst(N), nxt(n + 1);

    for(int i = 1; i <= n; i++) {
        if(!fir[s[i]]) fir[s[i]] = i;
        if(lst[s[i]])
            nxt[lst[s[i]]] = i;
        lst[s[i]] = i;
    }

    for(int i = 1; i <= n; i++) {
        if(lst[s[i]] == i)
            nxt[i] = fir[s[i]];
    }

    for(int i = 1; i <= n; i++) {
        int v = i % n + 1;
        G[i].push_back({v, a[v], i == n});
        v = nxt[i];
        G[i].push_back({v, 0,v <= i});
    }
    vector<P> dis(n + 1, {INF, INF});
    using PP = pair<P, int>;
    priority_queue<PP, vector<PP>, greater<PP>> pq;

    dis[1] = {a[1], 0};
    pq.push({dis[1], 1});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d != dis[u]) continue;
        for(auto [v, w, c] : G[u]) {
            P nd = {d.first + w, d.second + c};
            if(nd < dis[v]) {
                dis[v] = nd;
                pq.push({dis[v], v});
            }
        }
    }
    cout << dis[n].first << ' ' << dis[n].second + 1 << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
