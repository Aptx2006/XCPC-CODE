#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
#define int long long

const int MAXN = 1E5 + 5, MOD = 998244353, INF = 1E18;

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

class Martix {
public:
using gx = long long;
	int row, col;
	vector< vector<gx> > data;
	Martix(int row, int col) {
		this->row = row, this->col = col, data.resize(row);
		for (int i = 0; i < row; i++)
			data[i].resize(col);
	}
	Martix mul(Martix rhs, int mod = MOD) {
		Martix res(row, rhs.col);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < rhs.col; j++)
				for (int k = 0; k < col; k++)
					res.data[i][j] = (res.data[i][j] + data[i][k] * rhs.data[k][j]) % mod;
		return res;
	}

	void unit() {//单位矩阵
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (i == j) data[i][j] = 1;
	}
	
	Martix qpow(int mi, int mod = 1e9 + 7) const {
		Martix res(row, col), tmp = *this;
		res.unit();
		while (mi) {
			if (mi & 1)
				res = res.mul(tmp, mod);
			tmp = tmp.mul(tmp, mod);
			mi >>= 1;
		}
		return res;
	}
	
	void print() const {
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cout << data[i][j] << " \n"[j == col - 1];
	}
	
	void fill(gx x) {
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				data[i][j] = x;
	}
};

int n, m, q, t, ans, cnt, k;
string s;

void solve() { 
    cin >> n >> q >> s;
    vector<int> pi = mxMatch(s);
    Martix dp(n, n);
    for(int i = 0; i < n; i++) {
        t = i;
        while(1) {
            if(t < n and s[t] == '0') {
                t++;
                break;
            }else {
                if(!t)  break;
                t = pi[t-1];
            }
        }
        if(t < n)  dp.data[i][t]++;
        if(dp.data[i][t] >= MOD) dp.data[i][t] -= MOD;
		t = i;
        while(1) {
            if(t < n and s[t] == '1') {
                t++;
                break;
            }else {
                if(!t)  break;
                t = pi[t-1];
            }
        }
        if(t < n)  dp.data[i][t]++;
        if(dp.data[i][t] >= MOD) dp.data[i][t] -= MOD;
	}

    vector<Martix> pre{dp};
    for(int i = 0; i <= 60; i++) pre.push_back(pre[i].mul(pre[i]));

    while (q--) {
        cin >> m;
        //Martix res = dp.qpow(m, MOD); 
        vector<int> b(n, 0); b[0] = 1;
        for(int k = 0; k <= 60; k++) {
            if((m >> k) & 1) {
                vector<int> tb(n, 0);
                for(int j = 0; j < n; j++) {
                    t = 0;
                    for(int i = 0; i < n; i++) {
                        t += b[i] * pre[k].data[i][j];
                        if (t >= MOD) t %= MOD;
                    }
                    tb[j] = t;
                }
                b = tb;
            }
        }
        ans = 0;
        for (int j = 0; j < n; ++j) {
            //ans = ans + res.data[0][j];
            ans += b[j];
            if(ans >= MOD) ans -= MOD;
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; //cin >> times;
    while (times--) solve();
    return 0;
}
