#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    i64 l = 1, r = 1e9;
    i64 ans = 0;

    auto isok = [&](int k) {
        priority_queue<int> pq;
        for(auto x : a) {
            if(x > 0) pq.push(x);
        }
        for(int i = k - 1; i >= 0; i--) {
            if(pq.empty()) return true; 
            int x = pq.top();
            pq.pop();
            if(i <= 30) {
                x -= (1 << i);
                if(x > 0) {
                    pq.push(x);
                }
            }
        }
        return pq.empty();
    };

    while(l <= r) {
        i64 mid = (l + r) >> 1;
        if(isok(mid)) {
            ans = mid;    
            r = mid - 1;
        } else {
            l = mid + 1;  
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
