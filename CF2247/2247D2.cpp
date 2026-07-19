#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << x << endl;

const int inf = 1e9;
int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    int B = max(1, (int)sqrt(n) + 1);
    int sz = (n + B - 1) / B;
    vector<int> bmn(sz, inf), bmx(sz, -inf);
    auto init = [&](int id) {
        int l = id * B;
        int r = min(n, l + B);
        bmn[id] = inf;
        bmx[id] = -inf;
        for(int i = l; i < r; i++) {
            bmn[id] = min(bmn[id], a[i]);
            bmx[id] = max(bmx[id], a[i]);
        }
    };
    for(int i = 0; i < sz; i++) init(i);
    auto query = [&](int l, int r) -> pair<int,int> {
        int mn = inf, mx = -inf;
        while(l <= r and l % B != 0) {
            mn = min(mn, a[l]);
            mx = max(mx, a[l]);
            l++;
        }
        while(l + B - 1 <= r) {
            int id = l / B;
            mn = min(mn, bmn[id]);
            mx = max(mx, bmx[id]);
            l += B;
        }
        while(l <= r) {
            mn = min(mn, a[l]);
            mx = max(mx, a[l]);
            l++;
        }
        return {mn, mx};
    };
    vector<int> xjs;
    for(int len = 1; len < n; len <<= 1) xjs.push_back(len);
    if(xjs.empty() or xjs.back() < n) {
        xjs.push_back(xjs.empty() ? 1 : xjs.back() << 1);
    }
    vector<int> buc(xjs.size(), 0);
    auto isok = [&](int i, int b) {
        int len = xjs[i];
        if(b <= 0 or b >= n) return false;
        auto [lx, ly] = query(b - len, b - 1);
        auto [rx, ry] = query(b, min(n - 1, b + len - 1));
        return ly > rx;
    };
    for(int i = 0; i < (int)xjs.size(); i++) {
        int len = xjs[i];
        for(int b = len; b < n; b += len) {
            buc[i] += isok(i, b);
        }
    }
    auto calc = [&]() {
        // for(int len = 1; ; len <<= 1) {
        //     bool ok = 1;
        //     for(int i = len; i < n; i += len) {
        //         auto [lx, ly] = query(i - len, i - 1);
        //         auto [rx, ry] = query(i, min(n - 1, i + len - 1));
        //         if(ly > rx) {
        //             ok = 0;
        //             break;
        //         }
        //     }
        //     if(ok) {
        //         if(len == 1) return 0;
        //         return len / 2;
        //     }
        // }
        for(int i = 0; i < (int)xjs.size(); i++) {
            if(!buc[i]) {
                if(xjs[i] == 1) return 0;
                return xjs[i] >> 1;
            }
        }
        return 0;
    };
    cout << calc() << '\n';
    while(m--) {
        int ii, x;
        cin >> ii >> x;
        for(int i = 0; i < (int)xjs.size(); i++) {
            int len = xjs[i];
            int bid = ii / len;
            int l = bid * len;
            int r = (bid + 1) * len;
            if(l > 0 and l < n) buc[i] -= isok(i, l);
            if(r < n) buc[i] -= isok(i, r);
        }
        a[ii] = x;
        init(ii / B);
        for(int i = 0; i < (int)xjs.size(); i++) {
            int len = xjs[i];
            int bid = ii / len;
            int l = bid * len;
            int r = (bid + 1) * len;
            if(l > 0 and l < n) buc[i] += isok(i, l);
            if(r < n) buc[i] += isok(i, r);
        }
        cout << calc() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}