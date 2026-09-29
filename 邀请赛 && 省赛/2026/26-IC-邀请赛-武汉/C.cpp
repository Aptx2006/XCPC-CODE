#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m;

void solve() {
    int n;cin>>n;
    int s,d,hp;cin>>s>>d>>hp;
    for(int i=1;i<=n;i++){
        int a,k;cin>>a>>k;
        int att=min(3,a),def=min(3,5-a);
        if(att*s>=hp){
            cout<<"Yes\n"<<i<<'\n';return;
        }
        if(k>def*d){
            cout<<"No\n";return;
        }
        def=(k+d-1)/d;
        att=min(att,3-def);
        hp-=att*s;
    }
    cout<<"No\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
