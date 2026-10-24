#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

using P = pair<i64, i64>;

const int N = 3e5 + 5;
const i64 INF = 4e18;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
struct nod{
    i64 low,high;
};
void solve() {
    int n;cin>>n;
    i64 x,y;cin>>x>>y;
    i64 ans=0,ans1=0;
    vector<i64>a(n+1),b(n+1);
    vector<nod>nodd(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    i64 cur=0;
    vector<i64>num;
    for(int i=1;i<=n;i++){
        nodd[i].low=max(0ll,cur-(a[i]-a[i-1]));
        cur=max(cur-(a[i]-a[i-1]),b[i]);
        nodd[i].high=cur;
        ans+=(cur-nodd[i].low)*y;
        num.push_back(nodd[i].low);
        num.push_back(nodd[i].high);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    sort(nodd.begin()+1,nodd.end(),[](nod a1,nod a2){
        return a1.low<a2.low;
    });
    ans1=ans;
    //cout<<ans<<' ';
    priority_queue<i64,vector<i64>,greater<i64>>Q;
    i64 curlen=0,last=0,p=1;
    for(int i=0;i<num.size();i++){
        i64 maxx=num[i];
        
        while(p<=n and nodd[p].low<maxx){
            Q.push(nodd[p].high);
            p++;
        }
        while(!Q.empty() and Q.top()<maxx){
            Q.pop();
        }
        curlen+=(maxx-last)*Q.size();
        ans=min(ans,ans1-curlen*y+maxx*x);
        last=maxx;
    }
    cout<<ans<<'\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;cin>>T;
    while(T--) solve();
    return 0;
}