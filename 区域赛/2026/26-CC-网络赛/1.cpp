#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[10],b[40];
int v[10],flag=1;
void dfs(int cur,int res,int tar,int las){
    if(!flag)return;
    if(res<0)return;
    if(cur==6){
        if(tar<19)return;
        cout<<"YES\n";
        for(int i=0;i<5;i++)cout<<v[i]<<" ";
        cout<<v[5]+res<<"\n";
        flag=0;
        return;
    }
    for(int i=las;i<=6;i++){
        int ci=i,vi=a[i]+1;
        v[cur]=vi;
        dfs(cur+1,res-vi,tar+ci,i);
    }
    if(!flag)return;
}

void solve() {
    for(int i=1;i<=6;i++)cin>>a[i];
    sort(a+1,a+7);
    int n;cin>>n;
    dfs(0,n,0,0);
    if(flag)cout<<"NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}