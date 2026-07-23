#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5,M = 1e9+7;
int n,m,a[N],q,k;
#define dbg(A) cout<<#A<<':'<<A<<endl;
void solve(){
    cin>>n>>k>>q;
    vector<pair<int,int>>task(n);
    for(auto &[x,y]:task) cin >> x >> y;
    int hour=0;
    vector d(n+1,vector<pair<int,int>>(5));
    for(int day=1;day<=3;day++){
        //dbg(day);
        for(int i=0;i<n;i++){
            if(hour/k==day-1){
                hour=max(hour,(day-1)*k+task[i].first-1);
            }
            hour+=task[i].second;
            d[i+1][day] = {(hour+k-1)/k,(hour-1+k)%k+1};
            //cout<<" "<<"task "<<i+1<<"  need "<<(hour+k-1)/k<<" "<<(hour-1+k)%k+1<<endl;
        }
        if(hour<day*k)hour=day*k;
    }
    int delta = (d[1][3].first-1)*k + d[1][3].second - ( (d[1][2].first-1)*k + d[1][2].second );
    //dbg(delta);
    while(q--){
        int day,i;
        cin >> day >> i;
        if(day<=3){
            auto [x,y] = d[i][day];
            cout<<x<<" "<<y<<'\n';
        }else{
            auto [x,y] = d[i][3];
            int dy = (day-3) * delta;
            x = x+(y+dy+k-1)/k-1;
            y = (y+dy-1)%k+1;
            cout<<x<<" "<<y<<'\n';
        }
    }
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    //int times;cin >> times;while(times--) 
    solve();
    return 0;
}
