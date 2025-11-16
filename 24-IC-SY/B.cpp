#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(A) cout<<#A<<':'<<A<<'\n';
#define all(A) A.begin(),A.end()
using ld = long double;
mt19937_64 rnd (time(0));
const int N = 2e5+5, M = 1e9+7;
int n,m,a[N];
void solve(){
    cin >> n >> m;
    if(n==m and n==1){
        cout<<"Yes\n"<<"0\n0\n";return;
    }if(n==m or (n%2==0 and m%2==0)){
        cout<<"No\n";return;
    }if(n==1 or m==1){
        if(n==1){
            cout<<"Yes\n1\n";
            for(int i=0;i<m;i++) cout<<i<<' ';
            cout<<"\n";
        }else{
            cout<<"Yes\n";
            for(int i=0;i<n;i++) cout<<i<<' ';
            cout<<"1\n";
        }
        return;
    }
    int G[n][m]{};
    vector<int>a(n),b(m);
    //for(int i=0;i<100000;i++){
        a[0] = b[0] = 1;
        for(int i=1;i<n;i++) a[i] = a[i-1]+m;
        for(int i=1;i<m;i++) b[i] = b[i-1]+n;
        // for(int i=1;i<n;i++) a[i] = rnd()%(n*m);
        // for(int i=1;i<m;i++) b[i] = rnd()%(n*m);
        vector<int>buc(n*m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                G[i][j] = (a[i]*b[j])%(n*m);
                if(buc[G[i][j]]) goto A;
                buc[G[i][j]]++;
            }
        }
        cout<<"Yes\n";
        for(auto x:a) cout<<x<<' ';cout<<endl;
        for(auto x:b) cout<<x<<' ';cout<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<G[i][j]<< ' ';
        //     }cout<<"\n";
        // }
        return;
        A: ;
        cout<<"No\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}