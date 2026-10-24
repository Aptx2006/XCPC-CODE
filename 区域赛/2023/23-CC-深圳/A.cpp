#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define all(A) A.begin(), A.end()
#define dbg(A) cerr << (#A) << ':' << (A) << endl;
const int N = 1005;
int n;
vector<int> a, b, G[N];
vector<pair<int, int>> ans;

void dfs(int l, int r, int val) {
    //dbg(l) dbg(r) dbg(val) dbg(a[l])
    if(val != a[l]) {
        for(int j = l; j < r; j++) {
            for(auto &i: G[a[j]]) {
                ans.push_back({2, i});
            }
        }
        for(int x = val + 1; x < a[l]; x++) {
            ans.push_back({1, x});
        }
    }
    if(r == l + 1) return;
    int mid = l + r >> 1;
    dfs(mid, r, a[l]);
    dfs(l, mid, a[l]);
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
        G[x].push_back(i);
    }
    a = b;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    int sz = a.size();
    dfs(0, sz, 0);
    cout << ans.size() << '\n';
    for(auto &[x, y]: ans) cout << x << ' ' << y << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}