#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<int> mxl(n + 5), mnl(n + 5, n + 1);
    int mx = 0, mn = n;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        int l = u, r = v - 1;
        mx = max(mx, l), mn = min(mn, r);
        mxl[r] = max(mxl[r], l), mnl[r] = min(mnl[r], l);
    }
    vector<int> premx(n + 5), sufmn(n + 5, n + 1);
    premx[0] = mxl[0];
    sufmn[n + 1] = mnl[n + 1];
    for(int i = 1; i <= n; i++) {
        premx[i] = max(mxl[i], premx[i - 1]);
    }
    for(int i = n; i >= 1; i--) {
        sufmn[i] = min(mnl[i], sufmn[i + 1]);
    }
    for(int i = max(2, mx); i <= n - 1; i++) {
        int l = max(1, premx[i - 1]);
        int r = min(n + 1, sufmn[i]);
        int limit = min({mn, r - 1, i - 1});
        if(l <= limit) {
            cout << "Yes\n" << l + 1 << " " << i + 1 << "\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
