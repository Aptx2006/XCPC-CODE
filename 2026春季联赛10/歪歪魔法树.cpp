// Problem: 歪歪魔法树
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1206&pid=1002
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
// writen by slightar

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
#define point pair<int,int>
#define x first
#define y second
const int mod=998244353,N=2e5+8;
int n,m,k,a[N];
vector<int>G[N];
int inv6=166374059,inv2=499122177;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>sum(n+1,0);
	auto dfs=[&](auto &&dfs,int x, int fa)->void{
		sum[x]=a[x];
		for(int nx:G[x]){
			if(nx==fa) continue;
			dfs(dfs,nx,x);
			sum[x]=(sum[x]+sum[nx])%mod;
		}
	};
	dfs(dfs,1,0);
	int ans=0;
	auto dfs2=[&](auto &&dfs2,int x, int fa)->void{
		int res=0;
		vector<int>num;
		for(int nx:G[x]){
			if(nx==fa) continue;
			num.push_back(sum[nx]);
			res=(res+sum[nx])%mod;
		}
		
		int tans=0;
		for(int nx:num){
			tans=(tans+a[x]*nx%mod*(res-nx+mod))%mod;
		}
		tans=tans*inv2%mod;
		ans=(ans+tans)%mod;

		int s1=0,s2=0,s3=0;
		if(num.size()>=3){
			for(int nx:num){
				s1=(s1+nx)%mod;
				s2=(s2+nx*nx)%mod;
				s3=(s3+(nx*nx)%mod*nx)%mod;
			}
			ans=(ans+(
			s1*s1%mod*s1%mod-3*s1%mod*s2%mod+2*s3%mod+mod
			)%mod*inv6%mod+mod)%mod;
		}
		for(int nx:G[x]){
			if(nx==fa) continue;
			dfs2(dfs2,nx,x);
		}
	};
	dfs2(dfs2,1,0);
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)
	solve();
	return 0;
}
