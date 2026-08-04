#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using pii = pair<i64, i64>;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans;
const i64 MOD = 998344353;

class Martix {
public:
#define gx long long
	int row, col;
	vector<vector<gx> > data;
	Martix(int row, int col) {
		this->row = row, this->col = col, data.resize(row);
		for (int i = 0; i < row; i++)
			data[i].resize(col);
	}
	Martix mul(Martix rhs, int mod = 1e9 + 7) {//矩阵乘法
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
	
	Martix qpow(int mi, int mod = 1e9 + 7) const {//矩阵快速幂
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

void solve() {
    cin >> n >> m;
    vector<vector<int>> st;
    if(n == 1) {
        st.push_back({0});
    } else {
        for(int mask = 0; mask < (1 << (n - 2)); mask++) {
            vector<int> cur(n);
            cur[0] = 0;
            cur[1] = 1;
            for(int i = 2; i < n; i++) {
                int last = cur[i - 1];
                int bit = (mask >> (i - 2)) & 1;
                int tmp[2], idx = 0;
                for(int c = 0; c < 3; c++) {
                    if(c != last) tmp[idx++] = c;
                }
                cur[i] = tmp[bit];
            }
            st.push_back(cur);
        }
    }
    int sz = st.size();
    vector<vector<vector<int>>> G(sz);
    for(int i = 0; i < sz; i++) {
        vector<int> p = {0, 1, 2};
        do {
            vector<int> cur = st[i];
            for(int &x : cur) x = p[x];
            if(find(all(G[i]), cur) == G[i].end()) {
                G[i].push_back(cur);
            }
        } while(next_permutation(all(p)));
    }

    auto isok = [&](vector<int> &a, vector<int> &b) {
        if((i64)a.size() < n or (i64)b.size() < n) return false;
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) return false;
        }
        return true;
    };

    Martix mat(sz, sz);
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            i64 cnt = 0;
            for(auto &x: G[j]) {
                if(isok(st[i], x)) {
                    cnt++;
                }
            }
            mat.data[i][j] = cnt;
        }
    }
    mat.qpow(m - 1, MOD);
    i64 ans = 0;
    for(int i = 0; i < sz; i++) {
        i64 cur = 0, len = G[i].size();
        for(int j = 0; j < sz; j++) {
            cur = (cur + mat.data[i][j]) % MOD;
        }
        ans = (ans + cur * len) % MOD;
    }
  
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
