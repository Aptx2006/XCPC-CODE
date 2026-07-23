#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
#define dbg(A) cout<<#A<<" is "<<A<<'\n';
using ld = long double;
const int N = 2e5+5,M=1e9+7;
ld xball,yball,vxball,vyball;
ld Y1,y2,vy1,vy2;
ld x1,x2,vx1,vx2;
const ld eps=1e-8;
void solve(){
    cin>>xball>>yball>>vxball>>vyball;
    cin>>Y1>>y2>>vy1>>vy2;
    cin>>x1>>x2>>vx1>>vx2;
    ld t=(y2-Y1)/(vy1+vy2);
    ld yball=Y1+vy1*t;
    int fangxiang=0;
    if(vxball>0)fangxiang=1;
    else fangxiang=-1;
    for(int i=0;i<1000000 and fabsl(t)>eps;i++){
        if(fangxiang==1){
            if(vxball<0)vxball=-vxball;
            if(vxball<=vx2){
                xball=xball+t*vxball;
                t=0;
            }
            else{
            ld temptime=(x2-xball)/(vxball-vx2);
            if(temptime<t)t-=temptime;
            else{
                temptime=t;
                t=0;
            }
            xball=xball+temptime*vxball;
            x2=x2+vx2*temptime;
            x1=x1-vx1*temptime;
            fangxiang=-1;
        }
        }
        else{
            if(vxball<0)vxball=-vxball;
            if(vxball<=vx1){
                xball=xball-t*vxball;
                t=0;
            }
            else{
            ld temptime=(xball-x1)/(vxball-vx1);
            if(temptime<t)t-=temptime;
            else{
                temptime=t;
                t=0;
            }
            xball=xball-temptime*vxball;
            x2=x2+vx2*temptime;
            x1=x1-vx1*temptime;
            fangxiang=1;
        }
        }
    }
    cout<<fixed<<setprecision(8)<<xball<<" "<<yball<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}