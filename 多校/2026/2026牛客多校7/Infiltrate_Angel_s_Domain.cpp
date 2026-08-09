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
    ans = 0;
    auto isok = [&](int k) {
        int last = a[0];
        for(int i = 30; i >= 0; i--) {
            if((last >> i) & 1 and (k >> i) & 1) {
                last ^= (1 << i);
            }
        }
        for(int i = 1; i < n; i++) {
            int cur = a[i];        
            for(int j = 30; j >= 0; j--) {
                if((cur >> j) & 1 and (k >> j) & 1) {
                    cur ^= (1 << j);
                }
            }
            i64 res = 2e18;
            if((last & ~k) == cur) res = last;
            for(int j = 0; j <= 30; j++) {
                if(((last >> j) & 1) == 0) {
                    i64 cand = (last & ~((1ll << (j + 1)) - 1))|(1ll << j)|(cur & ((1ll << j) - 1));
                    if((cand & ~k) == cur) {
                        res = min(res, cand);
                    }
                }
            }
            if(res == 2e18) return false;
            last = res;
        }
        return true;
    };
    for(int i = 30; i >= 0; i--) {
        if(!isok(ans|((1 << i) - 1))) {
            ans |= (1 << i);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
