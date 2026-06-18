#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    set<vector<int>> st, tst;
    vector<int> a(n), b(n);
    auto add = [&](vector<int> x) {
        for(int i = 0; i < n; i++) {
            b[i] = x[a[i] - 1];
        }
        tst.insert(b);
    };
    for(int i = 0; i < m; i++) {
        for(auto &x: a) cin >> x;
        tst = st;
        for(auto &x: st) add(x);
        st = tst;
        st.insert(a);
    }
    cout << st.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(T = 1 ; T--; solve());
    return 0;
}
