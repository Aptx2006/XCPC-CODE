#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(), A.end()
const int N = 1e3 + 15, M = 1e9 + 7;
int n, m;
int ans[N][N];
int ans1[4][4]={{0,0,0,0},{0,0,1,1},{0,1,0,2},{0,2,2,0}};
int ans2[4][4]={{0,0,0,0},{0,2,2,0},{0,1,0,2},{0,0,1,1}};
void init(){
    for(int i=1;i<1005;i+=3){
        for(int j=1;j<1005;j+=3){
            if((i+j)%2==0){
                for(int ii=0;ii<3;ii++){
                    for(int jj=0;jj<3;jj++){
                        ans[i+ii][j+jj]=ans1[ii+1][jj+1];
                    }
                }
            }else{
                for(int ii=0;ii<3;ii++){
                    for(int jj=0;jj<3;jj++){
                        ans[i+ii][j+jj]=ans2[ii+1][jj+1];
                    }
                }
            }
        }
    }
}
void solve() {
    cin>>n>>m;
    if(n*m%3!=0){
        cout<<"No\n";
    }
    if(n==1||m==1){
        if(n==1&&m==3)cout<<"Yes\n012\n";
        else if(n==1&&m==6)cout<<"Yes\n001122\n";
        else if(n==3&&m==1)cout<<"Yes\n0\n1\n2\n";
        else if(m==1&&n==6)cout<<"Yes\n0\n0\n1\n1\n2\n2\n";
        else cout<<"No\n";
        return;
    }
    if(n==2||m==2){
        if(n==3){
            cout<<"Yes\n11\n22\n00\n";
        }else if(n==6){
            cout<<"Yes\n00\n00\n11\n11\n22\n22\n";
        }else if(m==3){
            cout<<"Yes\n012\n012\n";
        }else if(m==6){
            cout<<"Yes\n001122\n001122\n";
        }else{
            cout<<"No\n";
        }
        return;
    }
    cout<<"Yes\n";
    if(n<=m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<ans[i][j];
            }
            cout<<'\n';
        }
    }else{
       for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<ans[j][i];
            }
            cout<<'\n';
        }        
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1 ; cin >> T;
    while(T--) solve();
}