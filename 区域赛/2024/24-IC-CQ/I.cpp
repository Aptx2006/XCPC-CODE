#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20, MOD = 998244353;
int n,m,a[N];
//int qpow()
void solve(){
    for(int i=1;i<=9;i++) cin >> a[i];
    a[10]=0;
    int mn = min(a[1],a[2]);
    a[3] += mn;
    a[1] -= mn,a[2] -= mn;
    if(a[1]){
        if(a[1]>=3){
            a[3] += a[1]/3;
            a[1] %= 3;
        } 
        if(!(a[1]-1)){
            for(int i=2;i<=9;i++){
                if(a[i]) {
                    a[i]--,a[i+1]++,a[1]--;
                    break;
                }
            }
        }else{
            if(a[1])a[2]++,a[1]=0;
        }
    }
    //for(int i=1;i<=10;i++) cout<<i << ' '<<a[i]<<endl;
    int ans=1;
    for(int i=2;i<=10;i++){
        while(a[i]--){
            ans = (ans*i)%MOD;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times;cin >> times;
    while(times--)solve();
    return 0;
} 
