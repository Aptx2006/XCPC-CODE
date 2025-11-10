#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3005, MOD = 1e9+7;
int n,m,a[N],k,p;
int dp[N][N],g[N][N],h[N][N];
#define gx(A,B) for(int i=A;i!=B;i+=(B-A)/abs(A-B)); 
void solve(){
    map<char,int>mp;string s;
    for(int i=0;i<=256;i++)  mp[char(i)] = i;
	cin >> s >> k >>p;
	n=s.length();
	for(int i=0;i<n;++i) {
		h[0][i%p]++;
		if(s[i]=='\'')	g[0][i%p]++;
		else dp[0][i%p]+=mp[s[i]];
	}
    m=(n-1)%p;
    auto mod = [&](int x){
        return (x+MOD)%MOD;
    };
	for(int i=0;i<k;++i) {
        dp[i+1][0] = mod(dp[i+1][0]+mod((h[i][0]-1)*mp[' '])+mp['[']);
        int id = (5*m+4)%p;
        dp[i+1][id] = mod(dp[i+1][id]+mod((h[i][m]-1)*mp[','])+mp[']']);
		for(int j=0;j<p;++j) {
            id = (5*j+2)%p;
			dp[i+1][id]= mod(dp[i+1][id]+dp[i][j]);
            id = (5*j+1)%p;
			dp[i+1][id]= mod(dp[i+1][id]+g[i][j]*mp['"']);
            id = (5*j+3)%p;
			dp[i+1][id]= mod(dp[i+1][id]+g[i][j]*mp['"']);
			if(j!=0) {
                id = 5*j%p;
				dp[i+1][id]=mod(dp[i+1][id]+h[i][j]*mp[' ']);
			}
			if(j!=m) {
                id = (5*j+4)%p;
				dp[i+1][id]=mod(dp[i+1][id]+h[i][j]*mp[',']);
			}
			for(int t=0;t<5;++t) {
                id = (5*j+t)%p;
				h[i+1][id]=mod(h[i+1][id]+h[i][j]);
			}
            id = (5*j+1)%p;
			g[i+1][id]=mod(g[i+1][id]+mod(h[i][j]-g[i][j]));
            id = (5*j+3)%p;
			g[i+1][id]=mod(g[i+1][id]+mod(h[i][j]-g[i][j]));
            id = (5*j+2)%p;
			g[i+1][id]=mod(g[i+1][id]+g[i][j]);
		}
		m=(m*5+4)%p;
	}
	for(int i=0;i<p;++i) 
		cout<<mod(dp[k][i]+g[k][i]*mp['\''])<<' ';
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times=1;//cin >> times;
    while(times--)solve();
    return 0;
} 
