#include<bits/stdc++.h>
#define int long long

using namespace std;

int gcd(int a,int b){
	return (b==0)?a:gcd(b,a%b);
}
int fun(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
            x=x/i;
            if(x==2) return 2;
            else return x;
        }
	}

	if(x==2||x==3) return 1; 
	if(x==1) return -1;
	return 1;
}
void solve(){
	int x,y;
	cin>>x>>y;
	
	cout<<fun(gcd(x,y));
	
	
	
} 




signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
