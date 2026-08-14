#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    i64 x, a, b;
    cin >> x >> a >> b;
    i64 ans = (x + b - 1) / b;
    if(a == 1) {
        cout << ans << '\n';
        return;
    }
    
    i64 A = a - 1;
    for(i64 k = 1; ; k++) {
        i128 dmg = (i128)A * k * (k + 1) / 2 + k;
        if(dmg >= x) {
            ans = min(ans, k);
            break;
        }
        i64 rem = x - dmg;
        i64 s = k * A;
        
        i64 t;
        i128 sum = (i128)s * b + (i128)s * (s + 1) / 2;
        if(sum >= rem) {
            i64 l = 1, r = s;
            t = s;
            while(l <= r) {
                i64 mid = l + (r - l) / 2;
                i128 d = (i128)mid * b + (i128)mid * (2 * s - mid + 1) / 2;
                if(d >= rem) {
                    t = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        } else {
            i64 rem2 = rem - (i64)sum;
            t = s + (rem2 + b - 1) / b;
        }
        ans = min(ans, k + t);
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
