#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2005;
const int P=998244353;
int t,n,m,l;
const int dx[9]={0,0,0,1,1,1,-1,-1,-1},dy[9]={0,1,-1,0,1,-1,0,1,-1};

void A(){
    cin>>n>>m>>l;
    vector<vector<int>> a(n,vector<int>(m,0)),ans(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            ans[i][j]=0;
        }
    }
    auto cli = [&a,&ans](int x,int y,int k){
        ans[x][y]+=k;ans[x][y]%=l;
        for(int i=0;i<9;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<m)a[nx][ny]+=k,a[nx][ny]%=l;
        }
    };
    int flag=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            cli(i,j,l-a[i-1][j-1]);
        }
    }
    auto sol_l = [&cli](int i,int ti){
        if(m%3==0){
            for(int j=0;j<m;j+=3){
                cli(i,j,ti);cli(i,j+1,l-ti);
            }
        }else if(m%3==1){
            for(int j=0;j<m-1;j+=3){
                cli(i,j,l-ti);cli(i,j+1,ti);
            }
            cli(i,m-1,l-ti);
        }
    };
    if(m%3!=2){
        for(int i=1;i<n;i++){
            if(a[i-1][m-1]){
                int ti=a[i-1][m-1];
                sol_l(i,ti);
            }
        }
    }else{
        for(int i=0;i<n;i++){
            if(a[i][m-1]!=0){
                flag=0;break;
            } 
        }
    }
    auto sol_c = [&cli](int i,int ti){
        if(n%3==0){
            for(int j=0;j<n;j+=3){
                cli(j,i,ti);cli(j+1,i,l-ti);
            }
        }else{
            for(int j=0;j<n-1;j+=3){
                cli(j,i,l-ti);cli(j+1,i,ti);
            }
            cli(n-1,i,l-ti);
        }
    };
    if(n%3!=2){
        for(int i=1;i<m;i++){
            if(a[n-1][i-1]){
                int ti=a[n-1][i-1];
                sol_c(i,ti);
            }
        }
    }else{
        for(int i=0;i<m;i++){
            if(a[n-1][i]!=0){
                flag=0;break;
            } 
        }
    }
    if(a[n-1][m-1]){
        int ti=l-a[n-1][m-1];
        if(n%3==0){
            for(int j=0;j<n;j+=3){
                sol_l(j,ti);sol_l(j+1,l-ti);
            }
        }else{
            for(int j=0;j<n-1;j+=3){
                sol_l(j,l-ti);sol_l(j+1,ti);
            }
            sol_l(n-1,l-ti);
        }
    }
    if(flag){
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j])sum++;
            }
        }
        cout<<sum<<"\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j])cout<<i+1<<" "<<j+1<<" "<<ans[i][j]<<"\n";
            }
        }
    }else{
        cout<<"-1\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    t=1;
    cin>>t;
    while(t--){
        A();
    }
    return 0;
}
