#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m;
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};

void solve() {
    cin >> n >> m;
    map<string, i64> mp;
    for(int i = 0; i < m; i++) {
        string s;
        i64 x;
        cin >> s >> x;
        mp[s] = n * x;
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        string s;
        i64 x;
        cin >> s >> x;
        if(mp.count(s)) {
            mp[s] -= x;
        }
    }
    map<string, i64> mp2;
    for(auto &[x, y]: mp) {
        if(y > 0) {
            mp2[x] = y;
        }
    }

    if(mp2.empty()) {
        cout << "OK\n";
    }else {
        for(auto &[x, y]: mp2) {
            cout << x << ' ' << y << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
