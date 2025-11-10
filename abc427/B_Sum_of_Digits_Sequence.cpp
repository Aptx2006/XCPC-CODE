#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
void solve(){
    int n;
    cin >> n;
    vector<int>p(105),pre(105);
    p[0] = p[1] = 1;
    auto get = [](int x){
        int res=0;
        while(x){
            res+=x%10;
            x/=10;
        }return res;
    };
    for(int i=2;i<=100;i++){
        p[i] = get(p[i-1]) + p[i-1];
    }
    //for(int i=0;i<11;i++) cout<<p[i]<<' ';
    cout<<p[n]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
