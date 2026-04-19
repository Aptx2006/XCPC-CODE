#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int q; std::cin >> q;
    // std::vector<std::vector<int>> e(q + 1); // 有向树
    std::vector<int> f(q + 2); // 父节点
    std::vector<int> vis(q + 2); // vis[i] 节点i与f[i]的边是否会被砍掉
    int tot = 1; // 节点个数
    std::vector<std::pair<int, int>> query(q);
    for(int i = 0; i < q; i++) {
        std::cin >> query[i].first >> query[i].second;
        if(query[i].first == 1) {
            // e[query[i].second].push_back(++tot);
            f[++tot] = query[i].second;
            query[i].second = tot; // 意为 这次添加的边是tot与f[tot]
        }
        else if(query[i].first == 2) {
            if(vis[query[i].second]) query[i].second = 1;
            else vis[query[i].second] = true;
        }
    }

    std::vector<int> fa(tot + 1), val(tot + 1, 1);
    std::iota(fa.begin(), fa.end(), 0);
    auto find = [&](int x) -> int {
        int root = x;
        while(root != fa[root]) root = fa[root];
        while(x != root) {
            int nxt = fa[x];
            fa[x] = root;
            x = nxt;
        }
        return root;
    };

    for(int i = 2; i <= tot; i++) {
        // i --- f[i]
        if(vis[i]) continue;
        int u = i, v = f[i];
        int fu = find(u), fv = find(v);
        if(fu == fv) continue;
        fa[fv] = fu;
        val[fu] += val[fv];
    }

    std::vector<int> resv;

    std::reverse(query.begin(), query.end());
    for(auto [i, x]: query) {
        if(i == 1) {
            int fx = find(x);
            val[fx]--;
        }
        else if(i == 2) {
            int u = x, v = f[x];
            int fu = find(u), fv = find(v);
            if(fu == fv || u == 1) continue;
            fa[fv] = fu;
            val[fu] += val[fv];
        }
        else {
            resv.push_back(val[find(x)]);
        }
    }

    std::reverse(resv.begin(), resv.end());
    for(int x: resv) std::cout << x << '\n';
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
