#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5,M=1e9+7;
int n,m,a[N];
struct fwt{
    int sz;
    vector<int>tr;
    fwt(int _sz): sz(_sz),tr(_sz+1,0){}
    void upd(int i,int v){
        for(;i<=sz;i+=i&-i) tr[i]+=v;
    }
    int qry(int i,int res = 0){
        for(;i>0;i-=i&-i) res += tr[i]; 
        return res;
    }
};
fwt ans(N);
struct nod{
    int player1,player2;
};
vector<nod>play(N);
vector<int>G(N,0);
void init(){
    deque<int>Q;
    for(int i=1;i<=n;i++){
        Q.push_back(a[i]);
    }
    for(int i=1;i<n;i++){
        int a,b;
        a=Q.front();Q.pop_front();
        b=Q.front();Q.pop_front();
        play[i]={a,b};
        Q.push_back(min(a,b));
        ans.upd(i,max(a,b));
    }
}
void bfs(int d1,int d2,int l,int r){
    int winner1=max(play[d1].player1,play[d1].player2),
        winner2=max(play[d2].player1,play[d2].player2);
    int loser1 =min(play[d1].player1,play[d1].player2),
        loser2 =min(play[d2].player1,play[d2].player2);
    int last1=loser1,last2=loser2;
        
        if(d1==d2){swap(a[l],a[r]);return;}
        if(play[d1].player1==a[l])play[d1].player1=a[r];
        if(play[d1].player2==a[l])play[d1].player2=a[r];

        if(play[d2].player1==a[r])play[d2].player1=a[l];
        if(play[d2].player2==a[r])play[d2].player2=a[l];

        winner1=max(play[d1].player1,play[d1].player2),
        winner2=max(play[d2].player1,play[d2].player2);
    //ans[x] ->winner -ans[x];
    ans.upd(d1,winner1-(ans.qry(d1)-ans.qry(d1-1)));
    ans.upd(d2,winner2-(ans.qry(d2)-ans.qry(d2-1)));
    winner1=min(play[d1].player1,play[d1].player2),
    winner2=min(play[d2].player1,play[d2].player2);
    d1=G[d1];d2=G[d2];swap(a[l],a[r]);
    while(d1!=0&&d2!=0){
        last1=min(play[d1].player1,play[d1].player2);
        last2=min(play[d2].player1,play[d2].player2);//old minner

        if(play[d1].player1==loser1)play[d1].player1=winner1;
        if(play[d1].player2==loser1)play[d1].player2=winner1;//change old minner
        
        if(play[d2].player1==loser2)play[d2].player1=winner2;
        if(play[d2].player2==loser2)play[d2].player2=winner2;

        winner1=max(play[d1].player1,play[d1].player2);//get ans
        winner2=max(play[d2].player1,play[d2].player2);

        ans.upd(d1,winner1-(ans.qry(d1)-ans.qry(d1-1)));
        ans.upd(d2,winner2-(ans.qry(d2)-ans.qry(d2-1)));

        winner1=min(play[d1].player1,play[d1].player2);
        winner2=min(play[d2].player1,play[d2].player2);//new winner

        loser1=last1;loser2=last2;
        d1=G[d1];d2=G[d2];
    }
    
}
void solve(){   
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    int cnt=(1+n)/2;
    if(n%2==1){
        G[1]=cnt++;
        for(int i=2;i<n;i+=2){
            G[i]=(cnt);
            if(i+1<n)
            G[i+1]=(cnt);
            cnt++;
        }
        for(int i=1;i<=n;i++)if(G[i]>n-1)G[i]=0;
    }else{
        cnt++;
        for(int i=1;i<n;i+=2){
            G[i]=(cnt);
            if(i+1<=n)
            G[i+1]=(cnt);
            cnt++;
        }
        for(int i=1;i<=n;i++)if(G[i]>n-1)G[i]=0;
    }
    init();
    while(m--){
        char op;int l,r;
        cin>>op>>l>>r;
        if(op=='C'){
            int d1=(l-1)/2+1;
            int d2=(r-1)/2+1;
           // cout<<d1<<" "<<d2<<"\n";
            bfs(d1,d2,l,r);
        }else{
            cout<<ans.qry(r)-ans.qry(l-1)<<"\n";
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; 
    while(T--) solve();
}