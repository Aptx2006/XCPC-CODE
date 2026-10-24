#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define all(A) A.begin(), A.end()
#define dbg(A) cerr << #A << ':' << A << endl;

int n, m, k;
const int N = 2e5 + 5;
int x[N], y[N], z[N];

void solve(){
    cin >> n >> m >> k;
    i64 s = 0;
    for(int i = 0; i < m; i++) cin >> x[i] >> y[i] >> z[i], s += z[i];
    bool f = 1;
    i64 ans = 0;
    for(int i = 0; i < k; i++) {
        vector<int> tmp(n + 5, 0);
        for(int j = 0; j < m; j++) {
            if((z[j] >> i) & 1) tmp[x[j]] = tmp[y[j]] = 1;
            //dbg(tmp[x[i]])
        }
        for(int j = 0; j < m; j++) {
            if((z[j] >> i) & 1) continue;
            if(tmp[x[j]] and tmp[y[j]]) {
                //dbg(i)
                f = 0;
                break;
            }
        }
        if(f == 0) break;
        i64 sum = count(all(tmp), 1);
        //dbg(sum)
        ans += (1ll << i) * sum;
    }
    if(f) cout << ans << '\n';
    else cout << "-1\n";
    //dbg(s)
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1, r;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
