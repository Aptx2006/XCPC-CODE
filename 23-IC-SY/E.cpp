#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m,a[N],ans,q,p,x,y;
struct status{
    int lsheep,lwolf,rsheep,rwolf,step;
};
int mp[120][120][2];
bool check(status x,int newx,int newy){
    if(x.step%2==0){
        if(x.lsheep-newx!=0&&x.lsheep-newx+q<x.lwolf-newy)return 0;
        return 1;
    }else{
        if(x.rsheep-newx!=0&&x.rsheep-newx+q<x.rwolf-newy)return 0;
        return 1;
    }
}
bool check2(status s){
        if(mp[s.lsheep][s.lwolf][s.step&1]==0)return 1;
        if(mp[s.lsheep][s.lwolf][s.step&1]<=s.step)return 0;
        return 1;
}
void bfs(status x){
    queue<status>Q;
    Q.push(x);
    int cnt=0;
    while(!Q.empty()){
        cnt++;
       // if(cnt>=10000)break;
       
        status cur=Q.front();
         
        int lsheep=cur.lsheep,lwolf=cur.lwolf,rsheep=cur.rsheep,rwolf=cur.rwolf,step=cur.step;
        Q.pop();
        if(mp[cur.lsheep][cur.lwolf][cur.step&1]!=0&&mp[cur.lsheep][cur.lwolf][cur.step&1]<=step)continue;
            mp[cur.lsheep][cur.lwolf][cur.step&1]=step;
        if(lsheep==0){
            ans=min(ans,step);
            continue;
        }
        for(int i=0;i<=p;i++){
            for(int j=0;j<=i;j++){
                int changesheep=j,changewolf=i-j;
                // cout<<cur.lsheep<<" sheep "<<cur.lwolf<<" wolf step:"<<step<<endl;
                // cout<<"yunsong "<<j<<" sheep "<<i-j<<" wolf "<<endl;
                if(check(cur,changesheep,changewolf)){
                    if(step%2==1){
                    changesheep=0-changesheep;
                    changewolf=0-changewolf;
                }
                status news={lsheep-changesheep,lwolf-changewolf,
                rsheep+changesheep,rwolf+changewolf,step+1};
                //cout<<"push"<<news.lsheep<<" "<<news.lwolf<<" "<<news.step<<endl;
                    if(news.lsheep>=0&&news.rsheep>=0&&news.lwolf>=0&&news.rwolf>=0&&check2(news)){
                        
                        Q.push(news);
                    }
                }
            }
        }
    }
}
void solve(){
    cin >> x >> y >> p >> q;
    ans=1e8+5;
    bfs({x,y,0,0,0});
    if(ans==1e8+5)ans=-1;
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times = 1;//cin >> times;
    while(times--) solve();
    return 0;
}
