#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int mx = *max_element(all(a));
    
    vector<int> mp(n + 2, 0);
    for(int x : a) {
        if(x <= n + 1) mp[x]++;
    }
    
    vector<i64> res;
    res.push_back(mx);
    if(mx <= n + 1) {
        mp[mx]--;
    }
    
    int tag = 0;
    while(tag <= n and mp[tag] > 0) {
        res.push_back(tag);
        mp[tag]--;
        tag++;
    }
    
    int mx1 = mx;
    for(int i = 0; i < n; i++) {
        if(a[i] > n + 1 and a[i] != mx1) {
            res.push_back(a[i]);
        } else if(a[i] == mx1) {
            mx1 = -1; 
        } else {
            while(mp[a[i]] > 0) {
                res.push_back(a[i]);
                mp[a[i]]--;
            }
        }
    }
    
    i64 sum = 0, mx3 = -1;
    int mex = 0;
    vector<bool> vis(n + 2, false);
    
    for(int i = 0; i < n; i++) {
        mx3 = max(mx3, res[i]);
        if(res[i] <= n + 1) vis[res[i]] = true;
        while(vis[mex]) mex++;
        sum += mx3 + mex;
    }
    
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    solve();
}
