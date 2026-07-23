#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
int a[N];
void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>c;
    for(int i=0;i<k;i++){
        int l,r;cin>>l>>r;
        for(int j=l+1;j<=r;j++){
            a[j]=j-1;
        }
        c.push_back({l,r});
        a[l]=-1;
    }
    if(k==1){
        a[1]=0;
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" \n"[i==n];
        }
        return;
    }
    sort(c.begin(),c.end(),[](auto x,auto y){
        return x.second-x.first>y.second-y.first;
    });
    a[c[0].first]=0;
    bool f=0,f1=0;
    int maxx=c[0].second-c[0].first+1;
    for(int i=1;i<k;i++){
        if(c[i].second-c[i].first+1<=maxx-2){
            a[c[i].first]=c[0].first+1;f=1;
        }
        else{
            a[c[i].first]=c[0].first;f1=1;
        }
    }
    if(f1&&!f&&c[0].second-c[0].first==c[1].second-c[1].first){
        cout<<"IMPOSSIBLE\n";return;
    }
    for(int i=1;i<=n;i++){
            cout<<a[i]<<" \n"[i==n];
        }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int times;cin >> times;
    while(times--) solve();
    return 0;
}
