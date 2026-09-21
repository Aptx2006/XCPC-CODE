#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<pair<int, int>> ans;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] < a[i + 1]) {
            ans.emplace_back(a[i], a[i + 1]);
        }
    }
    while(m--) {
        int q;
        cin >> q;
        if(q > (int)ans.size()) {
            cout << "i don't know either\n";
        }else {
            auto &[x, y] = ans[q - 1];
            cout << "at " << q << ",student is " << x << ",teacher is " << y << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
