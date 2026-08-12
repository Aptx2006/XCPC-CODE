#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;
int n, m,T,s;

namespace my128 { // 读入优化封装，支持__int128
    using i64 = __int128_t;
    i64 abs(const i64 &x) {
        return x > 0 ? x : -x;
    }
    auto &operator>>(istream &it, i64 &j) {
        string val;
        it >> val;
        reverse(val.begin(), val.end());
        i64 ans = 0;
        bool f = 0;
        char c = val.back();
        val.pop_back();
        for (; c < '0' || c > '9'; c = val.back(), val.pop_back()) {
            if (c == '-') {
                f = 1;
            }
        }
        for (; c >= '0' && c <= '9'; c = val.back(), val.pop_back()) {
            ans = ans * 10 + c - '0';
        }
        j = f ? -ans : ans;
        return it;
    }
    auto &operator<<(ostream &os, const i64 &j) {
        string ans;
        function<void(i64)> write = [&](i64 x) {
            if (x < 0) ans += '-', x = -x;
            if (x > 9) write(x / 10);
            ans += x % 10 + '0';
        };
        write(j);
        return os << ans;
    }
}
using namespace my128;
const i64 mod=998244353;
void solve() {
    i64 n,x;cin>>n>>x;
    if(x==1){
        i64 sum=0;
        for(int i=1;i<=n;i++){
            i64 num;cin>>num;
            sum+=num;
        }
        cout<<sum<<'\n';return;
    }
    priority_queue<i64>Q;
    i64 cnt=0;i64 sum=0;
    for(int i=1;i<=n;i++){
        i64 num;cin>>num;
        cnt+=num/x;
        if(num%x!=x-1)Q.push(num%x);
    }
    while(!Q.empty()){
        i64 num=Q.top();
        Q.pop();
        i64 nd=min(cnt,(i64)(x-1-num));
        cnt-=nd;
        num+=nd;
        if(num!=x-1)Q.push(num);
        if(cnt==0)break;
    }
    cnt%=(x-1);
    sum+=cnt;
    while(!Q.empty()){
        sum+=Q.top();
        Q.pop();
        sum%=mod;
    }
    cout<<sum<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
