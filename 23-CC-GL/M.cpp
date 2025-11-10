#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define debug(x) cout<<#x<<'='<<x<<' ';
const int N = 3e5+5,MOD = 1e9 + 7;
int n,m,ans;
void solve(){
    cin >> n;
    vector<pair<int,int>>pos(n+1);
    unordered_set<int>mp;
    int mx = 0,u,v;
    for(int i=1;i<=n;i++){
        cin >> u >> v;
        mp.insert(u),mp.insert(v);
        pos[i] = {u,v};
        mx = max({u,v,mx});
    }
    auto isok = [&](int mid){
        int mx = 0,cnt = 0;
        for(auto [x,y]:pos) if(x>=mid) cnt++;
        vector<int>val(n+1,0),pv(n+1,0);
        for(int i=1;i<=n;i++){
            auto [x,y] = pos[i];
            if(x>=mid){
                if(y<mid) val[i] = -1;
            }else{
                if(y>=mid) val[i] = 1;
            }
        }
        for(int i=1;i<=n;i++) pv[i] = pv[i-1] + val[i];
        vector<int>rmx(n+1);//右端前缀和最大值
        rmx[n] = pv[n];
        //debug(cnt) cout<<endl;
        for(int i=n;i>1;i--) rmx[i-1] = max(rmx[i],pv[i-1]);
        // for(int i=1;i<=n;i++) debug(val[i]) cout<<endl;
        // for(int i=1;i<=n;i++) debug(pv[i]) cout<<endl;
        // for(int i=1;i<=n;i++) debug(rmx[i]) cout<<endl;
        int tmp = cnt;
        for(int i=1;i<=n;i++){
            tmp = max(tmp,cnt+rmx[i]-pv[i-1]);
            //if(tmp>=(n-1)/2 and !mp.count(mid)) return true;
            if(tmp>=(n+1)/2) return true;
        }
        return false;
    };
    int l = 0, r = mx;
    ans = 0;
    //debug(mx)
    while(l<=r){
        int mid = (l+r)>>1;
        //cout<<"mid="<<mid<<endl;
        if(isok(mid)){
            l=mid+1,ans = max(ans,mid);
        }else r =mid-1;
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times = 1;//cin >> times;
    while(times--) solve();
    return 0;
}
