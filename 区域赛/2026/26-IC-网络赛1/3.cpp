#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1000005,P=998244353;
int l[N],r[N],st[N];
char c[N];
vector<int> G[N];
map<int,int> mp;


void solve() {
    int n;
    cin>>n;
    mp.clear();
    int cnt=0;
    for(int i=1;i<=n;i++){
        string op;int val;
        cin>>op>>val;
        c[i]=op[0];
        if(op[0]=='+'){
            l[cnt]=i;r[cnt]=i;
            mp[val]=cnt;
            cnt++;
        }else if(op[0]=='T'){
            r[mp[val]]=i;
        }
    } 
    int top=0,pl=0,pr=0,p=0;
    for(int i=1;i<=n;i++){
        if(p<cnt&&l[p]==i){
            st[top++]=p;
            p++;
        }
        if(top&&r[st[top-1]]==i){
            while(top&&(r[st[top-1]]<=i)){
                r[st[top-1]]=i;
                top--;
            }
        }
    }
    sort(r,r+cnt);
    for(int i=1;i<=n;i++){
        if(c[i]=='+')cout<<c[i];
        else cout<<'?';
        while(pr<cnt&&r[pr]==i){
            cout<<'-';
            pr++;
        }
    }
    cout<<"\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
}
