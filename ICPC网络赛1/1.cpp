#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=100005,P=998244353;
int a[N],in[N],b[N],vis[N];
vector<int> G[N];

void init(){
    
}

void solve() {
    int n;
    cin>>n;
    a[0]=1;
    for(int i=1;i<=n;i++){
        cin>>in[i];
        vis[i]=0;
    }
    sort(in+1,in+n+1);
    int l=0,r=0;
    int pl=1,pr=1,p=1;
    while(p<=n){
        while(vis[pl])pl++,pr=max(pl,pr);;
        if(in[pl]==r){
            l++;
            b[p++]=r;
            vis[pl]=1;
            pl++;
            pr=max(pl,pr);
            continue;
        }
        while(in[pr]!=l)pr++;
        r++;
        b[p++]=l;
        vis[pr]=1;
        pr++;
    }
    int c0=0,c1=0;
    for(int i=1;i<=n;i++){
        int x=b[i];
        // cout<<"     "<<b[i]<<"\n";
        if(x==c0&&x==c1){
            a[i]=a[i-1]*2%P;
            c0++;
        }else if(x==c0){
            a[i]=a[i-1];
            c1++;
        }else if(x==c1){
            a[i]=a[i-1];
            c0++;
        }
        else a[i]=0;
    }
    cout<<a[n]<<"\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
}
