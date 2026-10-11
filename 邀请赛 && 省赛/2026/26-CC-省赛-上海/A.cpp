#include<bits/stdc++.h>
using namespace std;
#define all(A) (A).begin(), (A).end()
using i64 = long long;
using u64 = unsigned long long;
i64 n, m, k;
const u64 MOD = 1e9 + 7;

class HASH {
public:
    u64 operator ()(const vector<int> &o) const{
        u64 res = 0;
        for(auto &x: o){
            res ^= x + MOD;
        }
        return res;
    }
};

void solve() {
    cin >> n >> m >> k;
    vector G(n, vector<int>(m));
    for(auto &v: G) {
        for(auto &x: v) {
            cin >> x;
        }
    }
    unordered_map<vector<int>, set<int>, HASH> mp;
    if (k == 1){
        cout << m * (m - 1) / 2 << '\n';
        return;
    }else if (n == 1){
        cout << "0\n";
        return;
    }
    vector dif(n + 5, vector<int>(m + 5));
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            dif[i][j] = G[i + 1][j] - G[i][j];
        }
    }
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n - k + 1; i++) {
            vector<int> tmp(k - 1);
            for(int ni = i; ni < i + k - 1; ni++) {
                tmp[ni - i] = dif[ni][j];
            }
            mp[tmp].insert(j);
        }
    }
    vector ans(m, vector<int>(m));
    for(auto &[k, v]: mp) {
        vector tmp(all(v));
        for (int i = 0; i < (int)v.size(); i++) {
            for (int j = i + 1; j < (int)v.size(); j++) {
                ans[tmp[i]][tmp[j]] = 1;
            }
        }
    }
    i64 res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            res += ans[i][j];
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
