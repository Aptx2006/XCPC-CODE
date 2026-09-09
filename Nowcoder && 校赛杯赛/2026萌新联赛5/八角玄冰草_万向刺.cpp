#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

using nod = tuple<int, int, int>;

void solve(){
    int l;
    cin >> n >> m >> l;
    vector G(n, vector<string>(m));
    int hz, hx, hy;
    vector<nod> a;
    set<nod> mp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> G[i][j];
            for(int k = 0; k < l; k++) {
                if(G[i][j][k] == 'H') {
                    hz = i;
                    hx = j;
                    hy = k;
                }else if(G[i][j][k] == 'T') {
                    a.push_back({i, j, k});
                } 
            }
        }
    }
    for(auto &[i, j, k]: a) {
        int dz = i - hz;
        int dx = j - hx;
        int dy = k - hy;
        int g = __gcd(abs(dz), gcd(abs(dx), abs(dy)));
        dz /= g;
        dx /= g;
        dy /= g;
        mp.insert({dz, dx, dy});
    }
    cout << mp.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
