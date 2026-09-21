#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=200005;
const int P=998244353;
int n,m;
int a[N];

int qpow(int x,int y){
    int res=1;
    for(;y;y/=2,x*=x,x%=P)if(y&1)res*=x,res%=P;
    return res;
}

int cnt(int x,int y){
    int res=1;
    return res;
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=lower_bound(a+1,a+n+1,m)-a;
    int r=upper_bound(a+1,a+n+1,m)-a;
    int ans=0;
    for(int i=l;i<r;i++){
        ans+=cnt(i-1,n-i);
    }
    l=1,r=n;
    while(l<r){
        if(a[l]+a[r]<m*2){
            l++;continue;
        }
        if(a[l]+a[r]>m*2){
            r--;continue;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}