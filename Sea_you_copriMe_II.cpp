#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+10;
vector<int> vis(maxn),prime(maxn);
int pos;
int sieve(int n){
    int i,j,k;
    k=0;
    vis[0]=vis[1]=1;
    for(i=2;i<=n;i++){
        if(vis[i]==0)
            prime[k++]=i;
        for(j=2;i*j<=n;j++)
            vis[i*j]=1;
    }
    return k;
}
int gcd(int a,int b){
    while(b!=0){
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}
void find(int &now,vector<int>&cnt,int &ccnt){
        ccnt = 0;
        int p = 0; 
        vector<int> nowprime;
        while(now != 1 && p < pos) { 
            if(now % prime[p] == 0) {
                nowprime.push_back(prime[p]);
            }
            while(now % prime[p] == 0) {
                now /= prime[p];
            }
            p++;
        }
        if(now!=1){
            nowprime.push_back(now);
            now=1;
        }
        int l=1<<(nowprime.size());
        int n=nowprime.size();
        for(int mask=1;mask<l;mask++){
          int hh=mask;
          int shu=__builtin_popcount(mask);
          int cheng;
          if(shu&1) cheng=1;
          else cheng =-1;
          int prod=1;
          for(int k=0;k<n;k++){
            if(mask&(1<<k)){
                prod*=nowprime[k];
            }                
          }
          ccnt+=cnt[prod]*cheng;
        }
}
void add(int &now,vector<int> &cnt){
        int p=1;
        vector<int> nowprime;
        while(now!=1||p>pos){
            if(now%prime[p]==0){
                nowprime.push_back(prime[p]);
            }
            while(now%prime[p]==0){
                now/=prime[p];
            }
            p++;
        }
        if(now!=1){
            nowprime.push_back(now);
            now=1;
        }
        int l=1<<(nowprime.size());
        int n=nowprime.size();
        for(int mask=0;mask<l;mask++){
          int prod=1;
          for(int k=0;k<n;k++){
            if(mask&(1<<k)){
                prod*nowprime[k];
            }
          }
          cnt[prod]++;
        }
}
void delet(int &now,vector<int> &cnt){
    int p=1;
        vector<int> nowprime;
        while(now!=1||p>pos){
            if(now%prime[p]==0){
                nowprime.push_back(prime[p]);
            }
            while(now%prime[p]==0){
                now/=prime[p];
            }
            p++;
        }
        if(now!=1){
            nowprime.push_back(now);
            now=1;
        }
        int l=1<<(nowprime.size());
        int n=nowprime.size();
        for(int mask=0;mask<l;mask++){
          int prod=1;
          for(int k=0;k<n;k++){
            if(mask&(1<<k)){
                prod*nowprime[k];
            }
          }
          cnt[prod]--;
        }
}
void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n+2),cnt(n+2),ans(n+2), deg(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=1;
    //vector<int> zhishudui(3);
    vector<pair<int, int>> edges; 
    int qq=0;
    // for(int j=1;j<=n;j++){
    //     int now=a[j];
    //     int ccnt = 0;
    //     find(now,cnt,ccnt);
    //     if(ccnt!=j-i){
    //         if(zhishudui[0]!=0){
    //             if(gcd(zhishudui[0],a[j])!=1||qq==1){
    //                 ans[i]=j;
    //                 if(gcd(a[i],a[j])!=1){
    //                     zhishudui[0]=a[j];
    //                 }
    //                 int chuqu=a[i];
    //                 delet(chuqu,cnt);
    //                 i++;
    //                 j--;
    //                 continue;
    //             }
    //             if(gcd(zhishudui[0],a[j])==1){
    //                 qq++;
    //             }
    //         }
    //         else{
    //             zhishudui[0]=a[j];
    //         }
    //     }
    //     now=a[j];
    //     add(now,cnt);
    // }


}
signed main() {
    signed t_ = 1;
    cin >> t_;
    pos=sieve(maxn-5);
    while (t_--) {
        solve();
    }
}
