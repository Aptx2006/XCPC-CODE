#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=500005,P=998244353;
int nxt[N][26],cnt[N],t[N],ans[N];
int n,tot;

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<=tot;i++){
        memset(nxt[i],0,sizeof nxt[i]);
        cnt[i]=t[i]=0;
    }
    tot=0;
    for(int i=1;i<=n;i++)ans[i]=i;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        int p=0;
        for(int j=0;j<s.size();j++){
            if(!nxt[p][s[j]-'a']){
                nxt[p][s[j]-'a']=++tot;
            }
            p=nxt[p][s[j]-'a'];
            cnt[p]++;
            // cout<<"\t\t"<<i<<" "<<j<<" "<<p<<" "<<cnt[p]<<"\n";
            if(j+1>t[cnt[p]]){
                ans[i]-=(t[cnt[p]]^cnt[p]);
                t[cnt[p]]=j+1;
                ans[i]+=(t[cnt[p]]^cnt[p]);
            }
        }
        // cout<<"\t"<<tot<<"\n";
        // for(int j=1;j<=i;j++){
        //     cout<<ans[j]<<" \n"[j==i];
        // }
        // for(int j=1;j<=i;j++){
        //     cout<<t[j]<<" \n"[j==i];
        // }
    } 
    for(int i=1;i<=n;i++){
        ans[i]+=ans[i-1];
        cout<<ans[i]<<"\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
}
