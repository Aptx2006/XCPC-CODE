#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for(int i = n; i; i--) std::cin >> a[i];

    std::priority_queue<int> pq;
    for(int i = 1; i <= n; i++) {
        int x = a[i];
        if(pq.size() < k && 2 * (pq.size() + 1) <= i) pq.push(x);
        else if(!pq.empty() && x < pq.top()) {
            pq.pop();
            pq.push(x);
        }
    }

    LL res = 0;
    while(!pq.empty()) {
        res += pq.top();
        pq.pop();
    }

    std::cout << res << '\n';
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
