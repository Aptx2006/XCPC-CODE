#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1000005;
const int P=998244353;
int n,m;
int a[N],b[N],c[N];
int f[N],invf[N];
int vis[N];
int tot,flag=1;

int qpow(int x,int y){
    int res=1;
    for(;y;y/=2,x*=x,x%=P)if(y&1)res*=x,res%=P;
    return res;
}

int inv(int x){
    return qpow(x,P-2);
}

void init(){
    f[0]=invf[0]=1;
    for(int i=1;i<N;i++){
        f[i]=f[i-1]*i%P;
        invf[i]=inv(f[i]);
    }
}

int C(int x,int y){
    if(y>x)return 0;
    int res=1;
    return f[x]*invf[y]%P*invf[x-y]%P;
}

int getd(int x){
    int k=0;
    while(((1<<(k+1))-1)<x)k++;
    return k;
}

void dfs1(int u,int dep){
    int ca=(1ll<<(n-dep));
    int cb=((1ll<<n)-ca);
    if(dep<n){
        if(a[u]){
            int x=max(a[u*2],a[u*2+1]);
            if(x>a[u])flag=0;
            if(a[u*2]!=0){
                if(a[u*2]<a[u]){
                    a[u*2+1]=a[u];
                }
                if(a[u*2]==a[u]){
                    if(a[u*2+1]==a[u])flag=0;
                }
            }if(a[u*2+1]!=0){
                if(a[u*2+1]<a[u]){
                    a[u*2]=a[u];
                }
                if(a[u*2+1]==a[u]){
                    if(a[u*2]==a[u])flag=0;
                }
            }
        }
        dfs1(u*2,dep+1);
        dfs1(u*2+1,dep+1);
    }
    if(a[u]!=0&&a[u]<ca)flag=0;
}

void dfs(int u,int dep,int minn,int l,int r){
    if(a[u])minn=min(minn,a[u]);
    cout<<"\t\t"<<u<<" "<<minn<<"\n";
    if(dep<n){
        dfs(u*2,dep+1,minn,l,(l+r)/2);
        dfs(u*2+1,dep+1,minn,(l+r+1)/2,r);
    }else{
        b[l]=minn;
    }
}

void A(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        a[x]=y;
    }
    tot=(1<<n);
    dfs1(1,0);
    for(int i=1;i<=tot;i++)b[i]=n;
    dfs(1,0,tot,1,tot);
    if(flag==0){
        cout<<"0\n";return;
    }
    for(int i=1;i<tot*2;i++){
        if(a[i])vis[a[i]]=i;
        // cout<<a[i]<<" \n"[i==tot*2-1];
        // cout<<getd(i)<<" \n"[i==tot*2-1];

    }
    for(int i=1;i<=tot;i++){
        cout<<b[i]<<" "<<vis[i]<<"\n";
        // cout<<vis[i]<<" \n"[i==tot];
        c[b[i]]++;
    }
    int res=0,ans=1;
    for(int i=tot;i;i--){
        res+=c[i];
        if(vis[i]){
            ans*=(c[i]);ans%=P;
        }else{
            ans*=res;ans%=P;
        }
        res--;
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    init();
    while(t--){
        A();
    }
}