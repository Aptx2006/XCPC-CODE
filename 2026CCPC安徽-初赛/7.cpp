#include<bits/stdc++.h>
using namespace std;
using i128 = __int128;
#define int long long
#define all(A) A.begin(), A.end()

int n, m, k;

void solve(){
	cin >> n >> m >> k;
	int i = 0;
	i128 mm = m, nn = n;
	while(1){
		if(nn >= mm){
			cout << i << "\n";
			return;
		}
		nn = nn * (100 + k) / 100; 
		i++;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}