#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a[x - 1]++;
    }
    
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[a[i]]++;
    }

    while(1) {
        int mx = mp.rbegin()->first;
        int mn = mp.begin()->first;
        if(mx - mn >= 4) { 
            if(--mp[mx] == 0) mp.erase(mx);
            if(--mp[mn] == 0) mp.erase(mn);
            mp[mx - 1]++;
            mp[mn + 3]++;
        } else {
            break;
        }
    }
    
    cout << mp.rbegin()->first << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
