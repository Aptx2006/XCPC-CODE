#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=200005;
const int P=998244353;
vector<int> G[N];
string s;

int n;
int a[N],b[N];
int f[100];
void init(){
    f[0]=1;
    for(int i=1;i<15;i++)f[i]=f[i-1]*i;
}

void ec(int x){
    int vis[15];
    memset(vis,0,sizeof vis);
    if(n<14){
        for(int i=n-1;i>=0;i--){
            int y=x/f[i];x%=f[i];
            for(int i=0;i<15;i++){
                if(vis[i])continue;
                if(y==0){
                    vis[i]=1;
                    cout<<i+1<<" ";
                    break;
                }
                y--;
            }
        }
        cout<<"\n";
        return;
    }
    // cout<<"???"<<endl;
    for(int i=1;i<n-12;i++){
        cout<<i<<" ";
    }
    // cout<<endl;
    for(int i=n-12;i<=n;i++){
        int y=x/f[n-i];x%=f[n-i];
        for(int i=0;i<15;i++){
            if(vis[i])continue;
            if(y==0){
                vis[i]=1;
                cout<<n-12+i<<" ";
                break;
            }
            y--;
        }
    }
    cout<<"\n";
}
int dc(){
    int res=0;
    int p=1;
    // for(int i=0;i<=n;i++){
    //     cout<<a[i]<<"  ";
    // }
    // cout<<"\n";
    while(p<n&&a[p]==p)p++;
    for(int i=p;i<=n;i++){
        int cnt=0;
        // cout<<i<<"   "<<" \n"; 
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i])cnt++;
        }
        res+=cnt*f[n-i];
        // cout<<"\t\t"<<res<<" "<<cnt<<" "<<f[n-i]<<"\n";
    }
    return res;
}


void solve() {
    // a[1]=1;a[2]=3;a[3]=2;
    // cout<<"\t"<<dc();
    string op;cin>>op;
    if(op[0]=='f'){
        cin>>n;
        int x=-1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            // cout<<"\t"<<a[i]<<endl;
            x+=a[i];
            ec(x);
        }
    }else{
        cin>>n;
        int las=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[j];
            }
            b[i]=dc();
        }
        b[0]=-1;
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++){
            cout<<b[i]-b[i-1]<<" \n"[i==n];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    init();
    while(T--) solve();
    return 0;
}