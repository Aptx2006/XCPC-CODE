#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve(){
    cin>>n;
    auto find=[](i64 mod,i64 res,i64 n){
        i64 step = mod * (mod + 1);
        i64 c = (n + 1) / step; 
        i64 ans = c * mod; 
        i64 i = (c + 1) * step; 
        i64 l = i - mod; 
        if(l <= n){
            ans += (n - l + 1); 
        }
        return ans;
    };
    i64 res = 0;
    for(i64 i=1;i<=min(n,1000000ll);i++){
        res+=find(i,0,n);
    }
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}