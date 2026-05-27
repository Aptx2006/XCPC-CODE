#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

vector<int> mxMatch(string s){
	int len = s.length(),p = 0;
	vector<int>pi(len);
	//abababzabababa
	//0012340123456?(5)
	for(int i=1;i<len;i++){
		while(p and s[i]!=s[p])  p = pi[p-1];
		//既然s[i]!=s[p] 就让s[i]比较s[pi[p-1]] 以此往复......
		//因为pi[p-1]是s[p]的最大匹配长度 也就是次大匹配
		if(s[i] == s[p]) p++;
		pi[i] = p;
	}
	return pi;
}
vector<int> kmp(string text,string s){
	int len = text.length(),ls=s.length(),p=0;
	vector<int>pos,next;
	next = mxMatch(s);
	for(int i=0;i<len;i++){
		while(p and text[i]!=s[p]) p = next[p-1];
		if(text[i]==s[p]) p++;
		if(p==ls){
			pos.push_back(i-ls+1);
			p = next[p-1];//此处找到，那么后面继续找次大匹配
		}
		//这样理解更easy
		//pi[i] = p,ok[i] = (p[i]==ls) 
	}
	return pos;
}

void solve() {
    string s;
    cin >> s;
    vector<int> p = kmp(s, "execute");
    m = p.size();
    for(int i = m - 1; i >= 0; i--) {
        if(s[p[i] + 6] == 'e') s[p[i]] = '1';
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
