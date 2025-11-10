#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 3e5+5,MOD = 1e9 + 7;
int n,m,ans;
vector<int>mergee(vector<int>a,vector<int>b){
    int m=a.size();
    vector<int>ans(m,0);
    for(int i=0;i<m;i++){
        ans[i]=a[b[i]-1];
    }
    return ans;
}
void solve(){
    cin >> n >> m;
    vector a(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    set<vector<int>>mp;
    for(int i=0;i<m;i++){
        set<vector<int>>temp;
        for(auto x:mp){
            auto newone=mergee(x,a[i]);
            temp.insert(newone);
        }
        for(auto x:temp)mp.insert(x);
        mp.insert(a[i]);
    }
    cout<<mp.size();
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times = 1;//cin >> times;
    while(times--) solve();
    return 0;
}
