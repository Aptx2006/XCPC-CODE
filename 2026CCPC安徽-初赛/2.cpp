#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(A) A.begin(), A.end()
int n, m, q;

void solve(){
	cin >>n;
	string s, tmp;
	cin >> s;
	s += " ";
	set<char> space = {'#', '@', '$'};
	set<char> bd = {'!', ',', '.', '?'};
	for(int i = 0; i < n; i++) {
		if( space.count(s[i]) ) s[i] = ' ';
	}
	//cout << s << endl;
	for(int i = 0; i < n; i++) {
		if(s[i] == ' ') {
			reverse(all(tmp));
			cout << tmp << ' ';
			tmp = "";
		}else if(bd.count(s[i]) and (i == n - 1 or s[i + 1] == ' ')) {
			reverse(all(tmp));
			cout << tmp << s[i];
			tmp = "";
		}else {
			tmp += s[i];
		}
	}
	if((int)tmp.size()) {
		reverse(all(tmp));
		cout << tmp;
		tmp = "";
	}
	cout <<'\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}