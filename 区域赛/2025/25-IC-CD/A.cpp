#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(A) cout<<#A<<'='<<A<<' ';
const int N = 2e5+5,M = 1e9 + 7;
int n,m,a[N],b[N],ans,k;
void solve(){
    cin>>n;
    int sum=0;
    int c0=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c0+=(a[i]==0);
        sum+=a[i];
    }
    int l=0,r=0;
    for(int i=1;i<=n;i++){
        l+=10*a[i];
        r+=10*a[i];
        if(a[i]!=0)
            l-=5;
        r+=5;
    }
    //dbg(l)dbg(r)cout<<endl;
    if(1000>=r || l>1000){
        cout<<"No\n";return;
    }
    sum*=100;
    for(int i=1;i<=n;i++){
        //a[i]*=100;
        b[i] = a[i]*100;
        if(sum<10000){
            b[i]=a[i]*n+(100-sum/100);
        }else if(sum>10000){
            if(a[i]==0)continue;
            b[i]-=min(50ll,sum-10000);
            sum-=min(50ll,sum-10000);
        }
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    int sumb = 0;
    for(int i=1;i<=n;i++) sumb+=b[i];
    for(int i=1;i<=n;i++){
        double ai = a[i]/100.0;
        double fb = b[i]*1.0/sumb;
        //cout<<endl;dbg(ai) dbg(fb)
    }
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1; cin >> T;
    while(T--) solve();
    return 0;
}
