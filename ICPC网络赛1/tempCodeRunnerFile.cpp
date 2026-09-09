#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=500005,P=998244353;
int nxt[N][26],cnt[N],t[N],ans[N];
int n,tot;

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<tot;i++){
        memeset(nxt[i],0,sizeof nxt[i]);
        memeset(cnt[i],0,sizeof cnt[i]);
        ans[i]=t[i]=0;
    }
    for(int i=1;i<=n;i++){
        int ans=0;
        string s;cin>>s;
        int p=0;
        for(int j=0;j<s.size();j++){
            if(!nxt[p][s[j]-'a']){
                nxt[p][s[j]-'a']=tot++;
            }
            p=nxt[p][s[j]-'a'];
            cnt[p]++;
            if(j+1>t[cnt[p]]){
                ans[i]-=(t[cnt[p]]^cnt[p]);
                t[cnt[p]]=j+1;
                ans[i]+=(t[cnt[p]]^cnt[p]);
            }
        }
    } 
    for(int i=1;i<=n;i++){
        ans[i]+=ans[i-1];
        cout<<ans[i]<<" \n"[i==n];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
}
