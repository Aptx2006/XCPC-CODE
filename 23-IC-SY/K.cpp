#include <bits/stdc++.h>
using namespace std;
#define int long long
#define more int _;cin>>_;while(_--)
#define close ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define coutyes cout<<"Yes\n";
#define coutno cout<<"No\n";
#define all(A) A.begin(),A.end()
#define point pair<int,int>
#define x first
#define y second
const int mod=1e9+7,N=4e5+8;
int n,m,ans,cnt,k,l,r,a[N];
vector<int>num;int len;
int getrank(int x){
    return lower_bound(all(num),x)-num.begin()+1;
}
int getnum(int x){
    return num[x-1];
}
struct nod2{
    int p,cnt,num;
};
nod2 Segtree[N*4];
int lz[N*4];
void update(int p){
    Segtree[p].num=Segtree[p*2].num+Segtree[p*2+1].num;
    Segtree[p].cnt=Segtree[p*2].cnt+Segtree[p*2+1].cnt;
}
void build(int p,int l,int r){
    if(r<l)return;
    if(r==l){Segtree[p]={getnum(l),0,0}; return; };
    int mid=(l+r)/2;
    build(p*2,l,mid);build(p*2+1,mid+1,r);
    lz[p]=0;
    update(p);
}
void pushdown(int p){
    if(lz[p]){
        Segtree[p*2].cnt  +=lz[p];
        Segtree[p*2+1].cnt+=lz[p];
        lz[p*2]  +=lz[p];
        lz[p*2+1]+=lz[p];
        lz[p]=0;
    }
}
void change(int p,int l,int r,int ql,int qr,int v){
    if(ql>r||qr<l)return;
    //if(lz[p])pushdown(p);
    if(ql<=l&&qr>=r){
        Segtree[p].num+=Segtree[p].p*v;Segtree[p].cnt+=v;return;
        }
    //pushdown(p);
    int mid=(l+r)/2;
    change(p*2  ,l    ,mid,ql,qr,v);
    change(p*2+1,mid+1,r  ,ql,qr,v);
    update(p);
}
int rangesum(int p, int l, int r, int k) {
    if (k <= 0) return 0;  // 选0个，总和为0
    if (l == r) {  // 叶子节点：单独处理部分选的情况
        // 若需要选的k <= 该节点的正数个数，返回p*k；否则返回所有总和
        return min(k, Segtree[p].cnt) * Segtree[p].p;
    }
    if (Segtree[p].cnt <= k) return Segtree[p].num;  // 子树所有正数都选
    int mid = (l + r) / 2;
    // 左子树够选k个，仅选左子树的k个
    if (Segtree[p*2].cnt >= k) {
        return rangesum(p*2, l, mid, k);
    }
    // 左子树不够，选左子树所有 + 右子树剩余个数
    else {
        return Segtree[p*2].num+rangesum(p*2+1,mid+1,r,k- Segtree[p*2].cnt);
    }
}
int sum,bigger;
int query[N][2];
int hello(){
    if(sum==0||bigger==0)return 1;
    int bigsum=rangesum(1,1,len,bigger);  // 选所有正数的总和
    if (bigsum<=sum){
        return bigger+1;
    }
    int l=0,r=bigger;
    int up,mid;
    while(l<r){
        mid=(l+r)/2;
        if(rangesum(1,1,len,mid)<=sum){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    //cout<<bigger<<" "<<l<<"\n";
    if(l==0)return 1;
    return l;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0){num.push_back(a[i]);bigger++;}
        else sum-=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>query[i][0]>>query[i][1];
        if(query[i][1]>0)num.push_back(query[i][1]);
    }
    sort(all(num));
    num.erase(unique(all(num)),num.end());
    len=num.size();
    build(1,1,len);
    for(int i=1;i<=n;i++){
        if(a[i]>0)
        change(1,1,len,getrank(a[i]),getrank(a[i]),1);
    }
    for(int i=1;i<=m;i++){
        int ind=query[i][0],u=query[i][1];
        if(a[ind]>0){
            change(1,1,len,getrank(a[ind]),getrank(a[ind]),-1);
            bigger--;
        }else{
            sum+=a[ind];
        }
        a[ind]=u;
        if(a[ind]>0){
            change(1,1,len,getrank(a[ind]),getrank(a[ind]),1);
            bigger++;
        }else{
            sum-=a[ind];
        }
        cout<<hello()<<"\n";
    }
}
signed main(){
    close
    solve();

}
