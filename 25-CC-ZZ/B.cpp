#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
const int N = 1005, MOD = 1e9+7;
int n,l,h,w,p,q,r;
struct nod{
    int x,y,z;
};
void solve(){
    cin >> l >> h >> w;
    cin >> p >> q >> r;
    cin >> n;
    vector<nod> a(n);
    vector<int> xr, xrr, yr , yrr, zr, zrr;
    for(auto &[x,y,z]: a) {
        cin >> x >> y >> z;
        xr.push_back(x);
        yr.push_back(y);
        zr.push_back(z);
    }
    int sz = (p + 1) * (q + 1) * (r + 1);
    int need = n / sz; // 每一块里面需要有的数量
    if(need * sz != n) {
        cout << "0\n" ;
        return;
    }
    sort(xr.begin(), xr.end());
    sort(yr.begin(), yr.end());
    sort(zr.begin(), zr.end());
    int P = 0, k = n / (p + 1), ans = 1;
    for(int i = 0; i < p; i++) {
        P += k;
        (ans *= xr[P] - xr[P - 1]) %= MOD;
        xrr.push_back(xr[P - 1]);
    }
    P = 0, k = n / (q + 1);
    for(int i = 0; i < q; i++) {
        P += k;
        (ans *= yr[P] - yr[P - 1]) %= MOD;
        yrr.push_back(yr[P - 1]);
    }
    P = 0, k = n / (r + 1);
    for(int i = 0; i < r; i++) {
        P += k;
        (ans *= zr[P] - zr[P - 1]) %= MOD;
        zrr.push_back(zr[P - 1]);
    }
    map<tuple<int,int,int>,int> mp;
    int id = 0;
    for(auto &[x, y, z]: a) {
        int xx = lower_bound(all(xrr), x) - xrr.begin();
        int yy = lower_bound(all(yrr), y) - yrr.begin();
        int zz = lower_bound(all(zrr), z) - zrr.begin();
        mp[{xx, yy, zz}]++;
    }
    for(auto &[x ,y] : mp){
        if(y != need){
            cout << "0\n";
            return;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) solve();
}