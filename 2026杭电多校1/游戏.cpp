#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n;
    vector<i64> a(n+1),pre(n+1);
    i128 mxa=0,mxb=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    if(n&1){
        if(pre[n/2]>pre[n]-pre[n/2+1]){
            cout<<"YES\n";
        }else if(pre[n/2]==pre[n]-pre[n/2+1]){
            int flag=1;
            for(int i=1;i<=n/2;i++){
                if(pre[i]>pre[n]-pre[n-i]){
                    flag=0;
                }
                else if(pre[i]<pre[n]-pre[n-i]){
                    flag=1;
                }
            }
            if(flag) cout<<"NO\n";
            else cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }else{
        if(pre[n/2]>pre[n]-pre[n/2+1]){
            cout<<"YES\n";
        }else if(pre[n/2]==pre[n]-pre[n/2+1]){
            int flag=0;
            for(int i=2;i<=n/2;i++){
                if(pre[i]>pre[n]-pre[n-i + 1]){
                    flag=0;
                }
                else if(pre[i]<pre[n]-pre[n-i + 1]){
                    flag=1;
                }
            }
            if(flag) cout<<"NO\n";
            else cout<<"YES"<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
