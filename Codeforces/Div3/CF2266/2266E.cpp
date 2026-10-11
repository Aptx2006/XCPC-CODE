#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

const int V = 200000;
const i64 inf = 1e18;
i64 spf[V + 1];

void init() {
    for(int i = 0; i <= V; i++) spf[i] = i;
    for(i64 i = 2; i * i <= V; i++) {
        if (spf[i] == i) {
            for(i64 j = i * i; j <= V; j += i)
                if (spf[j] == j) {
                    spf[j] = i;
                }
        }
    }
}

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<i64> c(n + 1);
    for(int i = 1; i <= n; i++) {
        if(i <= k) { 
            c[i] = 0; 
            continue;
        }
        i64 best = inf;
        for(int j = i; j > 1;) {
            i64 p = spf[j];                     
            best = min(best, 1 + p * c[i / p]);
            while(j % p == 0) j /= p;           
        }
        c[i] = best;
    }
    i64 ans = 0;
    for(auto &x: a) ans += c[x];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(cin >> T; T--; solve());
    return 0;
}
