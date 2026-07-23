#include<bits/stdc++.h>
using namespace std;
using i128 = __int128;
#define int long long
#define all(A) A.begin(), A.end()
#define rall(A) A.rbegin(), A.rend()
int n, m, q , k;
const int maxn = 30;
struct bign{
	int len,s[maxn];
	bign(){
		memset(s,0,sizeof(s));
		len=1;
	}
	bign(int num){
		*this=num;
	}
	bign(const char* num) {
		*this = num;
	}
	string str() const {
		string res = "";
		for(int i  = 0; i <len; i++) res = (char)(s[i] +'0') +res;
		if(res == "") res = "0";
		return res;
	}
	bign operator =(const char* num){
		len=strlen(num);
		for(int i=0;i<len;i++)s[i]=num[len-i-1]-'0';
		return *this;	
	}
	bign operator + (const bign& b) const{
		bign c;
		c.len = 0;
		for(int i = 0, g = 0; g or i <max(len, b.len); i++) {
			int x = g;
			if(i <len) x += s[i];
			if(i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}
	bign operator +=(const bign& b){
		*this=*this+b;
		return *this;
	}
};
ostream& operator << (ostream &out,const bign &x){
	out<<x.str();
	return out;
}
void solve(){
	cin >> n;
	vector<int> a(n);
	for(auto &x: a) cin >> x;
	sort(rall(a));
	bign ans;
	for(int i = 0; i < (n - (n & 1)); i += 2) {
		bign x;
		string s = to_string(a[i] * a[i + 1]);
		char tmp[(int)s.size() + 1] = {0};
		for(int i = 0; i < (int)s.size(); i++) tmp[i] = s[i];
		x = tmp;
		ans += x;
	}
	cout << ans;
}

signed main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	solve();
}