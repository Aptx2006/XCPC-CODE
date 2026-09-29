#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=200005;
int n,m;
int a[N],b[N];

void init(){
}

void A(){
    cin>>n;
    int ans=1e18;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[n-i]=a[i];
    }
    if(n==1){
        cout<<a[0]<<"\n";
        return;
    }
    b[0]=a[0];
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" "<<b[i]<<"\n";
    // }
    int cur=a[0]*n+a[1]*(n-1);
    ans=min(ans,cur);
    for(int i=2;i<n;i++){
        cur-=a[i-2]*(n-i);
        cur+=a[i]*(n-i);
        ans=min(ans,cur);
    }
    
    cur=b[0]*n+b[1]*(n-1);
    ans=min(ans,cur);
    for(int i=2;i<n;i++){
        cur-=b[i-2]*(n-i);
        cur+=b[i]*(n-i);
        ans=min(ans,cur);
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--){
        A();
    }
}