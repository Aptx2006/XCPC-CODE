#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, cnt;
i64 ans;

const u64 BASE = 131;

struct Hash {
    vector<u64> h, pw;
    Hash(string s) {
        int n = s.size();
        h.resize(n + 1);
        pw.resize(n + 1);
        pw[0] = 1;
        for(int i = 0; i < n; i++) {
            h[i + 1] = h[i] * BASE + s[i];
            pw[i + 1] = pw[i] * BASE;
        }
    }
    u64 get(int l, int r) {
        return h[r] - h[l] * pw[r - l];
    }
};

void solve() {
    string s;
    cin >> s;
    n = s.size();
    string r = s;
    reverse(all(r));
    Hash ss(s), rr(r);

    auto lcp = [&](int l, int r, int lim) {
        int L = 0, R = lim;
        int res = 0;
        while(L <= R) {
            int mid = (L + R) >> 1;
            if(rr.get(n - 1 - l, n - 1 - l + mid) == ss.get(r, r + mid)) {
                res = mid;
                L = mid + 1;
            }else {
                R = mid - 1;
            }
        }
        return res;
    };

    auto fun = [&](int l, int r) {
        int lim = min(l + 1, n - r);
        int x = lcp(l, r, lim);
        if(x == lim) return lim;
        int rem = lim - x - 1;
        int y = lcp(l - x - 1, r + x + 1, rem);
        return x + y + 1;
    };
    ans = 0;
    
    for(int i = 0; i < n; i++) {
        ans += fun(i, i) + fun(i, i + 1);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
