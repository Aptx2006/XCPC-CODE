#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve(){
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    m = 100 * n;
    vector<bool> dp(m + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        int ai = a[i], sz = 100 / ai;
        vector<bool> ndp(m+1,0);
        for(int j = 0; j <= m; j++) { 
            if(!dp[j]) continue;
            for(int k = 0; k <= ai and j + k * sz <= m; k++)    ndp[j + k * sz] = 1;
        }
        dp.swap(ndp);
    }
    bool ok = true;
    for(int j = 0; j <= m; j++) if(!dp[j]){ ok = false; break; }
    cout << (ok?"Yes":"No") << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
