#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

i64 T, n, m, k, ans, cnt;

void solve() {
    i64 u, v;
    cin >> n >> k >> u >> v;
    i64 L = k - 1, R = n - k;
    ans = 4e18; 
    i64 c[] = {
        L, R,
        L + R / 2, 0,
        0, R + L / 2,
        0, 0
    };
    
    i64 rem = (L - R) % 3;
    if(rem < 0) rem += 3;
    
    for(int i = 0; i < 4; i++) {
        i64 l0 = c[i * 2], r0 = c[i * 2 + 1];
        i64 lst = max(0LL, l0 - 15), rst = max(0LL, r0 - 15);
        i64 len = l0 + 15, ren = r0 + 15;
        for(i64 l = lst; l <= len; l++) {
            for(i64 r = rst; r <= ren; r++) {
                if(2 * l + r > 2 * L + R or l + 2 * r > L + 2 * R) 
                    continue;
                if(l == 0 and r == 0 and (L != 0 or R != 0)) 
                    continue;
                i64 rem2 = (l - r) % 3;
                if(rem2 < 0) rem2 += 3;
                if(rem2 != rem) 
                    continue;
                ans = min(ans, u * l + v * r);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
