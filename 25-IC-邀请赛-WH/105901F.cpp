#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

const i64 INF =(1LL << 60), MOD = 998244353;
i64 T, n, m, k, ans, cnt;

i64 qpow(i128 base, i64 mi, i128 res = 1) {
    base %= MOD;
    while(mi) {
        if(mi & 1) res = res * base % MOD;
        base =(i128)base * base % MOD;
        mi >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    vector<pair<i64, i64>> v(n); 
    for(auto &[x, y]: v) cin >> y >> x; 

    sort(all(v), [&](auto &x, auto &y) {
        return x.first > y.first; 
    });

    vector<pair<i64, i64>> mp;
    for(auto &[b, a] : v) {
        if(!mp.empty() and mp.back().first == b) {
            mp.back().second += a;
        } else {
            mp.push_back({b, a});
        }
    }

    ans = 0;  
    i64 rem = 0, preb = -1;

    for(int i = 0; i < (int)mp.size(); ++i) {
        auto [b, cnt] = mp[i];
        if(i > 0 and rem > 0) {
            i64 gap = preb - b;
            if(gap >= 60) {
                rem = INF;
            } else {
                if(rem > (INF >> gap)) rem = INF;
                else rem <<= gap;
            }
        }

        preb = b;

        if(rem >= cnt) {
            rem -= cnt;
        }else {
            i64 need = cnt - rem;         
            i64 add =(need + m - 1) / m;  
            ans = (ans +(add % MOD) * qpow(2, b) % MOD) % MOD;
            i64 r = need % m;
            rem = (r == 0 ? 0 : m - r);
        }
    }

    cout << ans % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
