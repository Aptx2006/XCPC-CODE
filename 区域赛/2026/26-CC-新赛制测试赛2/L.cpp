/**********************************************************************
	Solution ID: 21543
	Problem: L
	User: team0307
	Language: C++
	Result: AC
	Time: 8ms
	Memory: 556KB
	Submit Time: 2026-10-11 14:57:59
	Code Length: 1258 chars
**********************************************************************/

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(A) cout << (#A) << ':' << A << endl;

int n, m;
struct nod{
    i64 x,len;
};
void solve() {
    int n,b,k;cin>>n>>b>>k;
    vector<int>a(b+1);
    a[0]=n;
    bool find=0;
    int sum=0,ans=0;
    auto dfs=[&](auto &&dfs,int x)->void{
        if(find)return;
        if(x==b+1){
            if(sum==n and ans==2*k+n){
                find=1;
                for(int i=1;i<=b;i++){
                    cout<<a[i]<<" \n"[i==b];
                }
                int st=1;
                for(int i=1;i<=b;i++){
                    int num=a[i];
                    for(int j=st+num-1;j>=st;j--){
                        cout<<j<<' ';
                    }
                    st+=num;
                }
                
            }
            return;
        }
        for(int i=1;i<=a[x-1];i++){
            a[x]=i;
            sum+=i;
            ans+=i*i;
            if(sum<=n)dfs(dfs,x+1);
            a[x]=0;
            ans-=i*i;
            sum-=i;
        }
    };
    dfs(dfs,1);
    if(!find)cout<<"IMPOSSIBLE\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
