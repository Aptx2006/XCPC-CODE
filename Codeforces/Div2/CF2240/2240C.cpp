#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    int xr = 0, pos = 0;
    for(auto x : a) {
        if(x > 0) {
            pos++;
        }
        xr ^= x;
    }
    if(pos < 2) { 
        cout << "0\n"; 
        return; 
    }
    if(xr == 0) { 
        cout << "1\n"; 
        return; 
    }

    ans = 0;
    for(auto x : a) {
        if((xr ^ x) <= x) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
