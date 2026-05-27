#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;
//快速傅里叶变换（FFT）
/*
题目描述
给定一个 n 次多项式 F(x)，和一个 m 次多项式 G(x)。
请求出 F(x) 和 G(x) 的乘积。
输入格式
第一行两个整数 n,m。PS：系数0-9
接下来一行 n+1 个数字，从低到高表示 F(x) 的系数。
接下来一行 m+1 个数字，从低到高表示 G(x) 的系数。
输出格式
一行 n+m+1 个数字，从低到高表示 F(x)⋅G(x) 的系数。
输入输出样例
输入 #1复制
1 2
1 2
1 2 1
输出 #1复制
1 4 5 2
*/
class FFT {
public:
    struct com {
        double x, y;
        com operator+(const com&t)const{
            return {x + t.x, y + t.y};
        }
        com operator-(const com&t)const{
            return {x - t.x, y - t.y};
        }
        com operator*(const com&t)const{
            return {x * t.x - y * t.y, x * t.y + y * t.x};
        }
    };

    static constexpr double PI = acos(-1);
    vector<com>A, B;
    vector<int>R;
    int la, lb, mi;

    FFT(int nn = 0, int mm = 0, int N = 1) {
        la = nn, lb = mm;
        A.resize(N), B.resize(N), R.resize(N);
        mi = 0;
    }

    void update() {
        for(mi = 1; mi <= la + lb; mi <<= 1);
    }

    void init(int nn, int mm) {
        la = nn, lb = mm;
        update();
        if((int)A.size() < mi) A.resize(mi);
        if((int)B.size() < mi) B.resize(mi);
        if((int)R.size() < mi) R.resize(mi);
        for(int i = 0; i < mi; i++) {
            A[i] = {0, 0};
            B[i] = {0, 0};
        }
    }

    void fun(int op, int ab) {
        vector<com>&C = (ab == 1 ? A : B);
        for(int i = 0; i < mi; i++) {
            R[i] = R[i >> 1] >> 1 | ((i & 1) ? (mi >> 1) : 0);
        }
        for(int i = 0; i < mi; i++) {
            if(i < R[i]) swap(C[i], C[R[i]]);
        }
        for(int len = 2; len <= mi; len <<= 1) {
            com w1 = {cos(2 * PI / len), sin(2 * PI / len) * op};
            for(int j = 0; j < mi; j += len) {
                com wk = {1, 0};
                for(int k = j; k < j + len / 2; k++) {
                    com x = C[k], y = C[k + len / 2] * wk;
                    C[k] = x + y;
                    C[k + len / 2] = x - y;
                    wk = wk * w1;
                }
            }
        }
    }

    vector<i64>multiply(const vector<i64>&a, const vector<i64>&b, int lim) {
        if(a.empty() || b.empty()) {
            return {};
        }

        init((int)a.size() - 1, (int)b.size() - 1);

        for(int i = 0; i < (int)a.size(); i++) {
            A[i].x = (double)a[i];
        }
        for(int i = 0; i < (int)b.size(); i++) {
            B[i].x = (double)b[i];
        }

        fun(1, 1), fun(1, 2);
        for(int i = 0; i < mi; i++) {
            A[i] = A[i] * B[i];
        }
        fun(-1, 1);

        int len = min(lim + 1, (int)a.size() + (int)b.size() - 1);
        vector<i64>ans(len);
        for(int i = 0; i < len; i++) {
            ans[i] = (i64)llround(A[i].x / mi);
        }
        return ans;
    }
}fft;

void solve() {
    int d;
    cin >> n >> d;
    d--;

    vector<vector<int>>G(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    i64 ans = 0;

    for(int rt = 1; rt <= n; rt++) {
        vector<i64>pre1(d + 1), pre2(d + 1);

        for(auto v : G[rt]) {
            vector<i64> depcnt(d + 1);

            auto dfs = [&](auto &&self, int u, int fa, int dep)->void{
                if(dep > d) {
                    return;
                }

                depcnt[dep]++;

                for(auto nxt : G[u]) {
                    if(nxt == fa) {
                        continue;
                    }
                    self(self, nxt, u, dep + 1);
                }
            };

            dfs(dfs, v, rt, 1);

            for(int x = 1; x < d; x++) {
                if(!depcnt[x]) {
                    continue;
                }
                ans += depcnt[x] * pre1[d - x];
                ans += depcnt[x] * pre2[d - x];
            }

            bool ok1 = false, ok2 = false;
            for(int x = 1; x <= d; x++) {
                if(depcnt[x]) ok1 = true;
                if(pre1[x]) ok2 = true;
            }

            if(ok1 and ok2) {
                vector<i64>tmp = fft.multiply( depcnt, pre1, d);
                for(int x = 0; x < (int)tmp.size(); x++) {
                    pre2[x] += tmp[x];
                }
            }

            for(int x = 1; x <= d; x++) {
                pre1[x] += depcnt[x];
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
