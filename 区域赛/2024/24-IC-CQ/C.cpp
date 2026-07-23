#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20, MOD = 998244353;
int n,m,a[N];
string G[10];
void solve(){
    cin >> n;
    string str = string(n+3,' ');
    for(int i=0;i<=7;i++) G[i] = str;
    cin >> G[1] >> G[7];
    int ct1 = 0,ct2 = 0;
    for(int i=0;i<n;i++) if(G[1][i]=='#') ct1++;
    for(int i=0;i<n;i++) if(G[7][i]=='#') ct2++;
    if(ct1==ct2 and ct1==n){
        cout<<"Yes\n";
        for(int i=0;i<7;i++) cout<<G[1]<<'\n';
        return;
    }else if(ct1==n or ct2==n){
        cout<<"No\n";return;
    }
    cout<<"Yes\n";
    for(int i=0;i<n;i++){
        if(G[1][i]=='#')G[2][i]='.';
        else G[2][i]='#';
        if(G[7][i]=='#')G[6][i]='.';
        else G[6][i]='#';
    }
    int x,y;
    for(int i=0;i<n;i++){
        if(i<=n-2&&G[2][i+1]=='#'&&G[2][i]=='.'){
            x=i;break;
        }
        if(i>=1&&G[2][i-1]=='#'&&G[2][i]=='.'){
            x=i;break;
        }
    }
    for(int i=0;i<n;i++){
        if(i<=n-2&&G[6][i+1]=='#'&&G[6][i]=='.'){
            y=i;break;
        }
        if(i>=1&&G[6][i-1]=='#'&&G[6][i]=='.'){
            y=i;break;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=x)G[3][i]='.';
        else G[3][i]='#';

        if(i!=y)G[5][i]='.';
        else G[5][i]='#';
    }
    if(x>y)swap(x,y);
    for(int i=0;i<n;i++){
        if(i>x&&i<y){
            G[4][i]='#';
        }else G[4][i] = '.';
    }
    if(y-x<=1)G[4][x]='#';
    for(int i=1;i<=7;i++) cout<<G[i]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times;cin >> times;
    while(times--)solve();
    return 0;
} 
