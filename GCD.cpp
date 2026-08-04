#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

vector<int> prime, minp;

void sieve(int n = 1e7) {
    minp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto j : prime) {
            if (j > minp[i] or j > n / i) break;
            minp[i * j] = j;
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

void solve() {
    i64 x;
    cin >> x;
    int mx = 0;
    i64 tmp = x;
    for(auto &p : prime) {
        if((i64)p * p * p > tmp) {
            break;
        }
        if(tmp % p == 0) {
            int cnt = 0;
            while(tmp % p == 0) {
                cnt++;
                tmp /= p;
            }
            mx = max(mx, cnt);
        }
    }    
    if(tmp > 1) {
        i64 sq = sqrt(tmp);
        if(sq * sq == tmp) {
            mx = max(mx, 2);
        } else {
            mx = max(mx, 1);
        }
    }
    ans = 0;
    while(mx > 0) {
        ans++;
        mx /= 2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    for(cin >> T; T--; solve());
    return 0;
}
