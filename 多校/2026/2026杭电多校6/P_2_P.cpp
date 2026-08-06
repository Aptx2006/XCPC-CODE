#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    i64 n;cin>>n;
    i64 sum=0;
    vector<i64>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>>G(n+1);
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        G[x].push_back(i);
    }
    i64 sum1 = -0, sum2 = 0;
    auto dfs=[&](auto &&dfs,int x,int c)->void{
         if (x != 1) {
            sum1 += a[x];
            sum2 += a[x] * (1 - c);
        }
        for(int v : G[x]) {
            int add = 0;
            if(v > x) add = 1;
            dfs(dfs, v, c + add);
        }
    };
    dfs(dfs,1,0);
    if(sum1 > 0) cout << 1 << "\n";
    else if(sum1 < 0) cout << -1 << "\n";
    else{
        if(sum2 > 0) cout << 1 << "\n";
        else if(sum2 < 0) cout << -1 << "\n";
        else cout << 0 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
