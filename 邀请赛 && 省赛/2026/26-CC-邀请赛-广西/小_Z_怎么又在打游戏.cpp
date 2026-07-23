#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dian{
	int l;
	int h;
	int op;
};
int mod=998244353;
int fact[101];
int quick(int a,int b){
	int ans=1;
	while(b){
		if(b%2==1) ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
void init(){
	fact[0]=1;
	for(int i=1;i<=100;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	for(int i=1;i<=100;i++){
		fact[i]=quick(fact[i],mod-2);
	}
}
void solve(){
	int n;
	cin>>n;
	vector<dian>a(n+1);
	vector<vector<int>>dp(n+1,vector<int>(101,0));
	vector<int>num;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].h>>a[i].op;
		num.push_back(a[i].l);
	}
	a[0].h=a[1].h;
	sort(num.begin(),num.end());
	num.erase(unique(num.begin(),num.end()),num.end());
	int len=num.size();
	unordered_map<int,int>ranktonum,numtorank;
	for(int i=0;i<len;i++){
		ranktonum[i+1]=num[i];
		numtorank[num[i]]=i+1;
	}
	vector<vector<int>>too(len+1,vector<int>(101,1));
	
	for(int i=1;i<=len;i++){
		for(int j=1;j<=100;j++){
			too[i][j]=too[i][j-1]*(ranktonum[i]+j-1)%mod;
			//if(j<=10)
			//cout<<too[i][j]<<' ';
		}	
	//	cout<<'\n';
	}
	
	for(int i=0;i<=100;i++){
		dp[0][i]=1;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i-1].h;j++){
			if(j>a[i].h)continue;
			if(a[i].op==1){
				for(int k=j+1;k<=a[i].h;k++){
					dp[i][k]=(dp[i][k]+dp[i-1][j]*too[numtorank[a[i].l]][k-j]%mod*fact[(k-j)%mod])%mod;
				}
			}
			else{
				for(int k=1;k<j;k++){
					dp[i][k]=(dp[i][k]+dp[i-1][j]*too[numtorank[a[i].l]][j-k]%mod*fact[(j-k)%mod])%mod;		
				}				
			}
			dp[i][j]+=dp[i-1][j];
			dp[i][j]%=mod;
		}
	}
//	for(int i=0;i<=n;i++){
//		if(i==0){
//			a[i].h=10;
//		}
//		for(int j=1;j<=a[i].h;j++){
//			cout<<dp[i][j]<<" \n"[j==a[i].h];
//		}
//	}	
	int ans=0;
	for(int i=1;i<=a[n].h;i++){
		ans+=dp[n][i];
		ans%=mod;
	}	
	cout<<ans<<"\n";
}  
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T=1;cin>>T;
    while(T--)solve();
    return 0;
}
