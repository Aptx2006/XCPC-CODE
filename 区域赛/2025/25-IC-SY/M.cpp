#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
using ld = long double;
const int N = 2e5+5,M = 1e9+7;
int a[10],b[10];
void solve(){
    for(int i=0;i<8;i++) cin >> a[i] >> b[i];
    vector<int>id(8);//i的种子顺位
    iota(all(id),0);
    auto cal = [&](int ix,int iy){
        int x,y;
        for(int i=0;i<8;i++){
            if(id[i]==ix) x = i;
            else if(id[i]==iy) y = i;
        }
        if(ix<iy) return a[x]*1.0/(a[x]+b[y])*1.0;
        return b[x]*1.0/(b[x]+a[y])*1.0;
    };
    double ans = 0.0;
    do{
        int i = id[0], d = (i>=4)*4;
        double res;
        // 第一场
        if(i-d==0) res = cal(0+d,1+d);
        else if(i-d==1) res = cal(1+d,0+d);
        else if(i-d==2) res = cal(2+d,3+d);
        else res = cal(3+d,2+d);
        // 第二场
        if(i-d<2) 
            res *= cal(2+d,3+d)*cal(i,2+d) + cal(3+d,2+d)*cal(i,3+d);
        else 
            res *= cal(0+d,1+d)*cal(i,0+d) + cal(1+d,0+d)*cal(i,1+d);
        // 第三场
        res *=  cal(4-d,5-d)*cal(6-d,7-d)*cal(4-d,6-d)*cal(i,4-d) +
                cal(4-d,5-d)*cal(7-d,6-d)*cal(4-d,7-d)*cal(i,4-d) +
                cal(5-d,4-d)*cal(6-d,7-d)*cal(5-d,6-d)*cal(i,5-d) +
                cal(5-d,4-d)*cal(7-d,6-d)*cal(5-d,7-d)*cal(i,5-d) +
                cal(4-d,5-d)*cal(6-d,7-d)*cal(6-d,4-d)*cal(i,6-d) +
                cal(5-d,4-d)*cal(6-d,7-d)*cal(6-d,5-d)*cal(i,6-d) +
                cal(4-d,5-d)*cal(7-d,6-d)*cal(7-d,4-d)*cal(i,7-d) +
                cal(5-d,4-d)*cal(7-d,6-d)*cal(7-d,5-d)*cal(i,7-d) ;
        ans = max(ans,res);
    }while(next_permutation(all(id)));
    cout<<fixed<<setprecision(10)<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) solve();
}
