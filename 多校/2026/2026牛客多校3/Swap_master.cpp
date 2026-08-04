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
    int v, r, c;
};
/*
    ans = sum_abs(a[i - 1] - a[i])
    {min(a[i-1], a[i]), max(a[i-1],a[i])}
    1.交换两个不重叠区间的端点，区间变大，最大增益为 2*(mxL - mnR)
        Lj = min(aj, aj+1) Ri = max(ai, ai+1)
    2.相邻、边界：暴力一下
    3.交换重叠区间的端点！！！ dp一下？枚举一下
*/
void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    i64 ans = 0;
    for(int i = 1; i < n; i++) {
        ans += llabs(a[i - 1] - a[i]);
    }
    i64 ans_ = ans;
    i64 mxL = -1e18;
    i64 mnR = 1e18;
    for(int i = 0; i < n - 1; i++) {
        mxL = max(mxL, min(a[i], a[i + 1]));
        mnR = min(mnR, max(a[i], a[i + 1]));
    }
    auto calc = [&](int x, int y) {
        if(x < 0 or x >= n or y < 0 or y >= n or x == y) return;
        vector<int> b;
        if(x != 0) b.push_back(x - 1);
        if(x != n - 1) b.push_back(x);
        if(y != 0) b.push_back(y - 1);
        if(y != n - 1) b.push_back(y);
        sort(all(b));
        b.erase(unique(all(b)), b.end());
        i64 bad = 0, add = 0;
        for(auto &p : b) {
            bad += llabs(a[p] - a[p + 1]);
        }
        swap(a[x], a[y]);
        for(auto &p : b) {
            add += llabs(a[p] - a[p + 1]);
        }
        swap(a[x], a[y]);
        ans_ = max(ans_, ans - bad + add);
    };
    for(int i = 0; i < n - 1; i++) {
        calc(i, i + 1);
    }
    for(int i = 1; i < n; i++) {
        calc(0, i);
    }
    for(int i = 0; i < n - 1; i++) {
        calc(n - 1, i);
    }
    ans_ = max(ans_, ans + 2 *(mxL - mnR));
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            auto getA = [&](int x){
                i64 cur = llabs(a[x - 1] - a[x]) + llabs(a[x] - a[x + 1]);
                i64 dp1 = 0;
                if(i == 0) dp1 = a[x - 1] + a[x + 1];
                else if(i == 1) dp1 = -a[x - 1] - a[x + 1];
                else dp1 = llabs(a[x - 1] - a[x + 1]);
              
                i64 dp2 = 0;
                if(j == 0) dp2 = -2 * a[x];
                else if(j == 1) dp2 = 2 * a[x];
                else dp2 = 0;
                return dp1 + dp2 - cur;
            };
            auto getB = [&](int x){
                i64 cur = llabs(a[x - 1] - a[x]) + llabs(a[x] - a[x + 1]);
                i64 dp1 = 0;
                if(i == 0) dp1 = -2 * a[x];
                else if(i == 1) dp1 = 2 * a[x];
                else dp1 = 0;
              
                i64 dp2 = 0;
                if(j == 0) dp2 = a[x - 1] + a[x + 1];
                else if(j == 1) dp2 = -a[x - 1] - a[x + 1];
                else dp2 = llabs(a[x - 1] - a[x + 1]);
                return dp1 + dp2 - cur;
            };
          
            i64 mxA = -1e18;
            for(int j = 3; j <= n - 2; j++) {
                mxA = max(mxA, getA(j - 2));
                ans_ = max(ans_, ans + mxA + getB(j));
            }
        }
    }
    
    cout << ans_ << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
