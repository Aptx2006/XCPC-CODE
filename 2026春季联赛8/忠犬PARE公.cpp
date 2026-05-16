#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()

const int N = 1000000, P = 1e9 + 7;

i64 inv[N + 5], inv2[N + 5];
i64 va[N + 5], vb[N + 5];
i64 F[N + 5];

void init() {
    inv[1] = inv2[1] = 1;
    for(int i = 2; i <= N; i++) {
        inv[i] = (P - P / i) * inv[P % i] % P;
        inv2[i] = inv[i] * inv[i] % P;
    }
}

int T, n, m;

void solve() {
    cin >> n >> m;
    int mx = 0;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        va[x] = (va[x] + x) % P;
        if(x > mx) mx = x;
    }
    for(int i = 0, x; i < m; i++) {
        cin >> x;
        vb[x] = (vb[x] + x) % P;
        if(x > mx) mx = x;
    }
    
    i64 ans = 0;

    for(int i = mx; i >= 1; i--) {
        i64 sa = 0, sb = 0;
        
        for(int j = 1; i * j <= mx; j++) {
            sa = (sa + va[i * j]) % P;
            sb = (sb + vb[i * j]) % P;
        }
        F[i] = sa * sb % P;
    
        for(int j = 2; i * j <= mx; j++) {
            F[i] = (F[i] - F[i * j] + P) % P;
        }
        ans = (ans + F[i] * inv2[i]) % P;
    }
    cout << ans << '\n';
    
    for(int i = 0; i <= mx; i++) va[i] = vb[i] = F[i] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(cin >> T; T--; solve());
    return 0;
}
