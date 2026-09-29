#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1000005;
const int P=998244353;
int n,m;
int a[N],b[N],c[N];
int f[N],invf[N];
int vis[N];
map<int,int> G[N];
set<pair<int,int> S;
set<int> H[N];
int flag=1,ans=1;
int tot=0;
int neg=0; 

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

// void sol(int u,int dep){
//     b[u]=1;
//     int ca=(1ll<<(n-dep));
//     int cb=((1ll<<n)-ca);
//     int res=1;
//     if(dep<n){
//         int x=max(a[u*2],a[u*2+1]);
//         if(x==0)res=
//         sol(u*2,dep+1);
//         sol(u*2+1,dep+1);
//     }
// }

// void dfs(int u,int dep){
//     int ca=(1ll<<(n-dep));
//     int cb=((1ll<<n)-ca);
//     if(dep<n){
//         if(a[u]<max(a[u*2],a[u*2+1]))flag=0;
//         dfs(u*2,dep+1);
//         dfs(u*2+1,dep+1);
//         G[u]=G[u*2];
//         // H[u]=H[u*2];
//         for(auto [k,v]:G[u*2+1]){
//             if(G[u].count(k))flag=0;
//             else G[u][k]=v;
//         }
//         // for(auto v:H[u*2+1]){
//         //     H[u].insert(v);
//         // }
//     }
//     if(a[u]==0)return;
//     if(a[u]<ca)flag=0;
//     // H[u].insert(a[u]);
//     G[u][a[u]]=ca-1;
// }

void dfs1(int u,int dep){
    int ca=(1ll<<(n-dep));
    int cb=((1ll<<n)-ca);
    if(dep<n){
        dfs1(u*2,dep+1);
        dfs1(u*2+1,dep+1);
        int x=max(a[u*2],a[u*2+1]);
        if(a[u*2]!=0&&a[u*2+1]!=0){
            if(a[u]!=0&&a[u]!=x)flag=0;
            else {
                a[u]=x;
                if(a[u*2]==x)a[u*2]=0;
                if(a[u*2+1]==x)a[u*2+1]=0;
            }
        }
    }
    if(a[u]!=0&&a[u]<ca)flag=0;
}

void dfs2(int u){
    int dep=getd(u);
    int ca=(1ll<<(n-dep));
    int cb=((1ll<<n)-ca);
    if(dep==n)return;
    if(a[u*2]!=0){
        S.insert({a[u*2],ca/2});
    }else{
        dfs(u*2);
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
    if(flag==0){
        cout<<"0\n";return;
    }
    for(auto [k,v]:G[1]){
        cout<<"\t"<<k<<" "<<v<<"\n";
    }
    sol(1,0);
    a[1]=tot;
    for(int i=1;i<tot*2;i++){
        if(a[i]!=0){
            dfs2(i);
            int res=(1<<getd(i));
            int cur=1,usd=0;
            sort(S.begin(),S.end());
            for(auto [x,y]:S){
                cur*=C(x-usd-1,y-1);cur%=P;
                cur*
                usd+=y;
            }
            ans*=cur;ans%=P;
            cur=1;
        }
    }
    // while(m--){
    //     int x,y;cin>>x>>y;
    //     int tot=(1<<n);
    //     int k=0;
    //     while(((1<<(k+1))-1)<x)k++;
    //     cout<<"\t"<<k<<"\n";
    //     int ca=(1<<(n-k));
    //     int cb=(tot-ca);
    //     cout<<ca<<" "<<cb<<"\n";
    //     int ans;
    //     ans=ca*inv(n)%P;
    //     ans=ans*C(y-1,ca-1)%P*f[ca]%P*f[cb]%P;
    //     cout<<ans<<"\n";
    // }
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