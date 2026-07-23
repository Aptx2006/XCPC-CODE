#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

set<vector<int>> st;
vector<pair<int, int>> state[6] = {
    {{1,1}}, {{1,2}, {2,1}}, {{1,3}, {3,1}}, 
    {{2,2}}, {{2,3}, {3,2}}, {{3,3}}
};

int tag;

void dfs(int mask, vector<int>& c) {
    if(mask == tag) {
        st.insert(c);
        return;
    }
    int pos = __builtin_ctz(~mask);
    int row = pos / 3, col = pos % 3;
    
    for(int t = 0; t < 6; t++) {
        for(auto [R, C] : state[t]) {
            if(row + R <= 3 and col + C <= 3) {
                int sub = 0;
                bool ok = true;
                for(int dr = 0; dr < R; dr++) {
                    for(int dc = 0; dc < C; dc++) {
                        int p =(row + dr) * 3 +(col + dc);
                        if(mask &(1 << p)) ok = false;
                        sub |=(1 << p);
                    }
                }
                if(ok) {
                    c[t]++;
                    dfs(mask | sub, c);
                    c[t]--;
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<i64> G[6];
    for(int i = 0; i < 9; i++) G[0].push_back(0); 
    
    for(int i = 0; i < n; i++) {
        int a, b, v;
        cin >> a >> b >> v;
        if(a > b) swap(a, b);
        if(a == 1 and b == 1) G[0].push_back(v);
        else if(a == 1 and b == 2) G[1].push_back(v);
        else if(a == 1 and b == 3) G[2].push_back(v);
        else if(a == 2 and b == 2) G[3].push_back(v);
        else if(a == 2 and b == 3) G[4].push_back(v);
        else if(a == 3 and b == 3) G[5].push_back(v);
    }
    
    for(int i = 0; i < 6; i++) {
        sort(G[i].rbegin(), G[i].rend());
    }
    
    i64 ans = 0;
    for(auto &c : st) {
        i64 cur = 0;
        bool ok = true;
        for(int i = 0; i < 6; i++) {
            if(G[i].size() < c[i]) { 
                ok = false; 
                break; 
            }
            for(int j = 0; j < c[i]; j++) cur += G[i][j];
        }
        if(ok) ans = max(ans, cur);
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 9; i++) tag += (1 << i);
    vector<int> tmp(6, 0);
    dfs(0, tmp);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
