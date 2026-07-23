#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double 
const int N = 2e5+5, MOD = 998244353;
#define eps(A) fixed << setprecision(A)
int n,m,a,b,c,d,e,f,ppmax;
void solve(){
   cin>>ppmax>>a>>b>>c>>d>>e>>f;
   int acc=(300*a+300*b+200*c+100*d+50*e);
   acc*=10000;
   acc=acc/(300.0*(a+b+c+d+e+f))+0.5;
   cout<<acc/100<<".";
   int res=acc%100;
   if(res<10)cout<<"0";
   cout<<res;
   
   cout<<"% ";
   int pp=0;
   pp=(320*a+300*b+200*c+100*d+50*e);
   pp*=5;pp*=ppmax;
   
   pp*=10;
   pp/=320*(a+b+c+d+e+f);
   pp-=40*ppmax;
   cout<<max((pp+5)/10,0ll);

   cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times;cin >> times;
    while(times--)solve();
    return 0;
} 
/*
2
630
3029 2336 377 41 10 61
3000
20000 10000 0 0 0 0
*/
