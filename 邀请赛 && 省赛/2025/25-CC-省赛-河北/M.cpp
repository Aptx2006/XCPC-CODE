#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

const i64 N = 20, M = 205;
i64 n, m, rkg, rks, rkb, pg, ps, pb, p[M];
string a[M];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++) cin >> a[i];
    cin >> rkg >> rks >> rkb >> pg >> ps >> pb;
    for(int b = 1; b < (1 << n); b ++) {
        vector<int> ans;
        for(int i = 0; i < n; i ++) {
            if(~b & (1<<i)) continue;
            ans.push_back(i);
        }
        if(ans.size() > 13 or ans.size() < 10) continue;
        for(auto &i : ans) 
            for(int j = 0; j < m; j ++) p[j] += (a[j][i] == '1');
        sort(p, p + m, greater<int>());
        if(p[rkg-1] == pg and p[rks-1] == ps and p[rkb-1] == pb) {
            cout << ans.size() << '\n';
            for(auto &x : ans)  cout << x + 1 << ' ';
            return;
        } 
        for(int j = 0; j < m; j ++) p[j] = 0;
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while(T--) solve();
}
