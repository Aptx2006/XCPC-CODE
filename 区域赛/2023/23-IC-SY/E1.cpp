#include <bits/stdc++.h>
using namespace std;
//#define int long long
struct node{int sheep,wolf,step;};//只存左边的狼羊数量
int res[120][120][2];//人在左边和右边分开存
int x,y,p,q,ans=2e8;
void solve(){
    cin>>x>>y>>p>>q;
    memset(res,0x3f,sizeof res);
    queue<node>Q;
    Q.push({x,y,0});
    while(!Q.empty()){
        auto [s,w,stp] = Q.front();
        Q.pop();//左边羊为0, 说明完成任务了
        if(s==0)    ans=min(ans,res[s][w][stp&1]);
        for(int i=0;i<=p;i++){//i 动物
            for(int j=0;j<=i;j++){//j sheep i-j wolf
                //检查渡河后羊会不会被吃
                int sheep = s - j,wolf = w - (i-j);//走了之后剩下的羊和狼
                if(stp&1) sheep = (x-s)-j,wolf = (y-w)-(i-j);//如果是从右边渡河
                if(sheep<0 or wolf<0) continue;//不合法
                if(sheep!=0 and sheep+q<wolf) continue;//羊会被吃掉
                int k = (stp&1)?1:-1;//比例系数,简化代码
                int ds = k*j, dw = k*(i-j);//左边的羊的变化值
                if(stp+1<res[s+ds][w+dw][stp&1]){
                    res[s+ds][w+dw][stp&1]=stp+1;
                    Q.push({s+ds,w+dw,stp+1});
                }
            }
        }
    }
    cout<<(ans==2e8?-1:ans)<<'\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
