#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=200005;
const int P=998244353;
int a[3][N];
set<int> ans;
int n;

void sol(int x,int y){
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(a[x][i]);
        s.insert(a[y][i]);
        if(s.size()==i)ans.insert(i);
    }
}

void solve() {
    ans.clear();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[0][i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[1][i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[2][i];
    }
    sol(0,1);
    sol(0,2);
    sol(2,1);
    cout<<ans.size()<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}