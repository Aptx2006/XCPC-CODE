#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 10;
int n, m, ans, cnt;
vector<int> G[N];

void solve() {
    cin >> n;
    vector<int> a(n), b(n), d(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i], d[i] = b[i] - a[i];
    ans = count(d.begin(), d.end(), 0);
    int add = 0;
    for(int L = 0; L < n; L++) {
        unordered_map<int, int> mp;
        cnt = 0;
        for(int R = 0; R < n; R++) {
            if(d[R] == 0) cnt++;
            else{
                mp[d[R]]++;
                add = max(add, mp[d[R]] - cnt);
            }
        }
    }
    cout << ans + add <<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}