#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
const int N = 1005,M=1e9+7;
int n,m;
void solve(){
    int a,b,c; 
    cin>>a>>b>>c;
    queue<int>Q;
    unordered_set<int>vis;
    auto Len = [](int x, int len = 0){
        while(x)  x>>=1, len++;
        return len;
    };
    int B = (1ll << Len(b));
    Q.push(a),Q.push(a^b);
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        if( x > max(c,c^b) )continue;
        if( c>=x and (c-x)%b == 0 or c>=(x^b) and (c-(x^b))%b == 0){
            cout<<"YES\n";return;
        }
        /*
        B是b最高位的2的幂次
        累加B次之后 mod b 的贡献之前与之前全部重复了
        */
        if( x >= a + B*b) continue;
        if(!vis.count(x+b)){
            Q.push(x+b);
            vis.insert(x+b);
        }
        if(!vis.count(x^b)){
            Q.push(x^b);
            vis.insert(x^b);
        }
    }
    cout<<"NO\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}