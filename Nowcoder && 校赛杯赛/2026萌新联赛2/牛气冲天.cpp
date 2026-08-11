#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using pbset = tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update>;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    // 提交错了 WA-2 没绷住
    cin >> n >> m;
    i64 G[n + 5][m + 5]{0}, g = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> G[i][j];
        }
    }
    i64 x;
    cin >> x >> k;
    i64 mid = 0;
    if(x & 1) {
        mid = (x * x + 1) / 2;
    }else {
        mid = (x * x) / 2;
        if(mid == 0) mid = 1;
    }
    for(int i = 1; i + x - 1 <= n; i++) {
        for(int j = 1; j + x - 1 <= n; j++) {
            vector<i64> tmp;
            tmp.reserve(x * x);
            for(int p = i; p < i + x; p++) {
                for(int q = j; q < j + x; q++) {
                    tmp.push_back(G[p][q]);
                }
            }
            nth_element(tmp.begin(), tmp.begin() + mid - 1, tmp.end());
            g = __gcd(g, tmp[mid - 1]);
            if(g == 1) break;
        }
        if(g == 1) break;
    }
    if(k % g == 0) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T ; T--; solve());
    return 0;
}
