#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cout<<#x<<'='<<x<<endl;
const int N = 5e5+5,MOD = 1e9 + 7;
int n,m,ans;
int a[N],b[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int cur=m;
    deque<int>dq;
    for(int i=n-m+1;i<=n;i++)dq.push_back(a[i]);
    int cnt=0;
    vector<int>ans;
    while(cur>=1){
        while(!dq.empty()&&dq.back()<b[cur]){
            int t=dq.back();ans.push_back(t);
            t++;dq.pop_back();dq.push_back(t);
        }
        if(dq.empty()){
            cout<<"-1\n";return;
        }
        cur--;
        dq.pop_back();cnt++;
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1;i<=n-m;i++)pq.push(a[i]);
    if(pq.empty()){
        cout<<ans.size()<<"\n";
        for(int o:ans)cout<<o<<" ";
        cout<<'\n';return;
    }
    if(n-m-cnt<0){cout<<"-1\n";return;}
    vector<int>ans1;
    for(int i=1;i<=n-m-cnt;i++){
        int x=pq.top();ans1.push_back(x);
        x++;pq.pop();pq.push(x);pq.pop();
    }
    cout<<ans1.size()+ans.size()<<"\n";
    for(int i:ans1)cout<<i<<" ";
    for(int i:ans)cout<<i<<" ";
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times = 1;cin >> times;
    while(times--) solve();
    return 0;
}
