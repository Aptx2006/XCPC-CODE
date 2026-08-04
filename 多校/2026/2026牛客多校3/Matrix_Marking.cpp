#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using pii = pair<i64, i64>;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans;

struct nod{
    int val, r, c;
};

void solve() {
    cin >> n >> m;
    vector G(n, vector<i64>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }
    vector<nod> a(n * m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            a[i * m + j] = {G[i][j], i + 1, j + 1};
        }
    }
    sort(all(a), [&](auto &o1, auto &o2) {
        if(o1.val != o2.val) return o1.val < o2.val;
        if(o1.r != o2.r) return o1.r < o2.r;
        return o1.c < o2.c;
    });

    vector<int> dif((n + 5) * (m + 5));

    auto add = [&](int r1, int r2, int c1, int c2) {
        dif[r1 * (m + 2) + c1]++;
        dif[r1 * (m + 2) + c2 + 1]--;
        dif[(r2 + 1) * (m + 2) + c1]--;
        dif[(r2 + 1) * (m + 2) + c2 + 1]++;
    };

    for(int L = 0, R; L < n * m; L = R) {
        R = L;
        while(R < n * m and a[R].val == a[L].val) {
            R++;
        }
        vector<int> row, mnc, mxc;
        for(int j = L; j < R;) {
            int r = a[j].r;
            int mn = a[j].c;
            int mx = a[j].c;
            while(j < R and a[j].r == r) {
                mx = a[j].c;
                j++;
            }
            row.push_back(r);
            mnc.push_back(mn);
            mxc.push_back(mx);
        }

        int sz = row.size();
        if(sz >= 2) {
            vector<int> premn(sz), sufmx(sz);
            premn[0] = mnc[0];
            for(int j = 1; j < sz; j++) {
                premn[j] = min(premn[j - 1], mnc[j]);
            }
            sufmx[sz - 1] = mxc[sz - 1];
            for(int j = sz - 2; j >= 0; j--) {
                sufmx[j] = max(sufmx[j + 1], mxc[j]);
            }
            for(int j = 0; j < sz - 1; j++) {
                if(premn[j] < sufmx[j + 1]) {
                    add(row[j], row[j + 1], premn[j], sufmx[j + 1]);
                }
            }
        }
    }

    for(int i = 1; i <= n + 1; i++) {
        for(int j = 1; j <= m + 1; j++) {
            dif[i * (m + 2) + j] += dif[i * (m + 2) + j - 1];
        }
    }
    for(int i = 1; i <= n + 1; i++) {
        for(int j = 1; j <= m + 1; j++) {
            dif[i * (m + 2) + j] += dif[(i - 1) * (m + 2) + j];
        }
    }
    for(int i = 1; i <= n; i++) {
        string res = "";
        for(int j = 1; j <= m; j++) {
            if(dif[i * (m + 2) + j] > 0) {
                res += '1';
            } else {
                res += '0';
            }
        }
        cout << res << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
