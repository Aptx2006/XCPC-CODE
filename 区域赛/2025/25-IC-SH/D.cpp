#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(A) cout << (#A) << ':' <<  (A) << endl;

const int N = 20;
int n, m;
i64 pw3[N];

void init() {
    pw3[0] = 1;
    for(int i = 1; i < N; i++) pw3[i] = pw3[i - 1] * 3;
}

void solve() {
    cin >> n;
    int sz = 1 << n;
    vector<int> a(sz), st(sz), ans(pw3[n]);
    for(auto &x: a) cin >> x;
    for(int i = 0; i < sz; i++) {
        int cur = 0;
        for(int j = 0; j < n; j++) {
            int bit = (i >> j) & 1;
            cur += bit * pw3[j];
        }
        //dbg(cur)
        st[i] = cur;        
        ans[cur] = a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int l = 0; l < pw3[i]; l++) {
            for(int r = 0; r < (1 << (n - i - 1)); r++) {
                int A = st[r] * pw3[i + 1] + l;
                int B = A + pw3[i];
                //dbg(A) dbg(B)
                ans[ A + 2 * pw3[i] ] = ans[A] + ans[B];
            }
        }
    }

    int res = 0;
    for(auto &x: ans) {
        res ^= x;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
