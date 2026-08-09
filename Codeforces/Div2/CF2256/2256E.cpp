#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

i64 extgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    i64 x1, y1;
    i64 d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

i64 getinv(i64 a, i64 m) {
    i64 x, y;
    extgcd(a, m, x, y);
    return (x % m + m) % m;
}

void first() {
    cin >> n;
    vector<string> G(n);
    for(auto &x: G) cin >> x;
    int x, y;
    cin >> x >> y;
    i64 cnt = 0, sumx = 0, sumy = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(G[i][j] == '#') {
                cnt++;
                sumx += i;
                sumy += j;
            }
        }
    }
    cnt %= n, sumx %= n; sumy %= n;
    i64 inv = getinv(cnt, n);
    i64 dr = ((x - 1 - (sumx * inv) % n) % n + n) % n;
    i64 dc = ((y - 1 - (sumy * inv) % n) % n + n) % n;
    dr = (dr * cnt) % n;
    dc = (dc * cnt) % n;
    if(dr == 0 and dc == 0) {
        cout << n << " " << n << " " << n << " " << n << "\n";
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(G[i][j] == '#') {
                int nr = (i + dr) % n, nc = (j + dc) % n;
                if(G[nr][nc] == '.') { 
                    cout << i + 1 << " " << j + 1 << " " << nr + 1 << " " << nc + 1 << "\n";
                    return;
                }
            }
        }
    }
}

void second() {
    cin >> n;
    vector<string> G(n);
    for(auto &x: G) cin >> x;
    i64 cnt = 0, sumx = 0, sumy = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(G[i][j] == '#') {
                cnt++;
                sumx += i;
                sumy += j;
            }
        }
    }
    cnt %= n, sumx %= n; sumy %= n;
    i64 inv = getinv(cnt, n);
    cout << (sumx * inv) % n + 1 << " " << (sumy * inv) % n + 1 << "\n";
}

void solve() {
    string s;
    cin >> s;
    if(s == "first") {
        for(cin >> T; T--; first());
    }else if(s == "second") {
        for(cin >> T; T--; second());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //for(; T--; solve());
    solve();
    return 0;
}
