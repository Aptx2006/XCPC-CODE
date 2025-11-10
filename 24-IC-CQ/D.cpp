#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5, MOD = 1e9+7;
int n,m,a,b;
set<int>num;
void dfs(int x){
    if(x>1000000)return;
    num.insert(x);
    dfs(x*2);
    dfs(x*5);
}

vector<int>bb;
void solve(){
    cin>>a>>b;
    a%=b;
    if(num.count(b)){
        cout<<"0 1\n";return;
    }
    int tar=b/a;
    for(int i=0;i<bb.size();i++){
        if(bb[i]>tar){
            tar=bb[i-1];break;
        }
    }
    //cout<<tar<<endl;
    int ans1=b-tar*a,ans2=tar*b;
    if(ans1!=0){
    int gcd=__gcd(ans1,ans2);
    ans1/=gcd;ans2/=gcd;
}
    cout<<ans1<<" "<<ans2<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    dfs(1);
    for(auto x:num) 
        bb.push_back(x);
    int times;cin >> times;
    while(times--)solve();
    return 0;
} 
