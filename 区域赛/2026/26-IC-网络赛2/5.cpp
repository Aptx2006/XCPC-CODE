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
    int cnt=0;
    memset(b,0,n*4+16);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<n&&b[a[i]]==0)b[a[i]]++;
        else c[cnt++]=a[i];
    }
    sort(c,c+cnt);
    cnt=unique(c,c+cnt)-c;
    int st=0;
    while(st<n&&b[st])st++;
    unordered_map<int,int> mp,amp;
    for(int x=0;x<n*2-1;x++){
        int p=cnt-1;
        int pb=n;
        for(int i=st;i<=n;i++){
            if(i==n){
                mp[x]=n;
                break;
            }
            if(i<pb&&b[i])continue;
            while(p>=0&&x-c[p]<i)p--;
            if(p>=0&&x-c[p]==i){
                continue;
            }
            if(x-i<n&&x-i>=0&&x-i>i){
                if(b[x-i]){
                    pb=min(pb,x-i);
                    continue;
                }
                else {
                    mp[x]=i;
                    break;
                }
            }else{
                mp[x]=i;
                break;
            }
        }
        // cout<<"    "<<x<<" "<<mp[x]<<"\n";
    }
    int cur=st;
    int pst=0;
    while(pst<cnt&&c[pst]<n)pst++;
    for(int p=pst;p<cnt;p++){
        amp[c[p]+st]=st+1;
    }
    for(int i=st+1;i<n;i++){
        if(b[i]){
            for(auto [x,y]:amp){
                if(amp[x]==i)amp[x]=i+1;
            }
        }else for(int p=pst;p<cnt;p++){
            if(amp.count(c[p]+i)&&amp[c[p]+i]==i)amp[c[p]+i]++;
        }
    }
    // for(auto [x,y]:mp){
    //     cout<<"\t"<<x<<" "<<y<<"\n";
    // }
    int ans=0;
    cin>>m;
    while(m--){
        int x;cin>>x;
        if(mp.count(x)){
            ans^=mp[x];
            // cout<<"  "<<mp[x]<<"\n";
        }else if(amp.count(x)){
            ans^=amp[x];
            // cout<<"  "<<amp[x]<<"\n";
        }else{
            ans^=st;
            // cout<<"  "<<st<<"\n";
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