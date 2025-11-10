#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,a,x,y,vis[N];
vector <int> v[N];
map <pair<int,int>,int> mp;
void dfs (int x) {
	vis[x]=1;
	for (auto y:v[x]) {
		if (vis[y]) {continue;}
		dfs(y);
	}
}
int main (int argc,char* argv[]) {
	registerValidation(argc,argv);
	n=inf.readInt(1,100000);
	inf.readSpace();
	ensuref(n&1,"n is odd\n");
	m=inf.readInt(0,100000);
	inf.readChar('\n');
	for (int i=1;i<=n;i++) {
		a=inf.readInt(1,n);
		if (i==n) {inf.readChar('\n');}
		else {inf.readSpace();}
	}
	for (int i=1;i<=m;i++) {
		x=inf.readInt(1,n);
		inf.readSpace();
		y=inf.readInt(1,n);
		inf.readChar('\n');
		ensuref(mp.find(make_pair(x,y))==mp.end(),"simple graph 1\n");
		ensuref(x!=y,"simple graph 2\n");
		v[x].push_back(y),v[y].push_back(x);
		mp[make_pair(x,y)]=mp[make_pair(y,x)]=1;
	}
	dfs(1);
	for (int i=1;i<=n;i++) {ensuref(vis[i],"connected graph\n");}
	inf.readEof();
	return 0;
}
