#include<bits/stdc++.h>
// #define int long long
using namespace std;

const int N=200005;
int n,m;
int a[N],b[N],c[N];

void init(){
}

void A(){
    cin>>n;
    memset(b,0,n*4+16);
    memset(c,0,n*4+16);
    unordered_map<int,int> mp;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<n&&b[a[i]]==0)b[a[i]]++;
        else c[cnt++]=a[i];
        // c[cnt++]=a[i];
    }
    int st=0;
    int ans=0;
    while(st<n&&b[st])st++;
    sort(c,c+cnt);
    cnt=unique(c,c+cnt)-c;
    cin>>m;
    // cout<<"\t"<<st<<"\n";
    while(m--){
        int x;cin>>x;
        if(mp.count(x)){
            // cout<<"  "<<mp[x]<<"\n";
            ans^=mp[x];
            continue;
        }
        int p=cnt-1;
        int pb=n-1;
        for(int i=st;i<=n;i++){
            if(i==n){
                mp[x]=n;
                // cout<<"  "<<n<<"\n";
                ans^=n;
                break;
            }
            if(b[i])continue;
            if(x-i<n&&x-i>=0&&x-i>i){
                if(b[x-i])continue;
                else {
                    // cout<<"  "<<i<<"\n";
                    ans^=i;
                    mp[x]=i;
                    break;
                }
            }
            while(p>=0&&x-c[p]<i)p--;
            if(p<0||x-c[p]!=i){
                // cout<<"  "<<i<<"\n";
                ans^=i;
                mp[x]=i;
                break;
            }
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--){
        A();
    }
}