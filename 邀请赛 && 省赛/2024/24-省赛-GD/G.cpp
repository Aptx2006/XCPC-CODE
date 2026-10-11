#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(A) cout << (#A) << ':' << A << endl;

int n, m;
const int N = 1e6;
i64 l, r, ans;

void solve() {
    cin >> l >> r;
    ans = 0;

    auto isok = [&](i64 x) {
        if(x == 0) return;
        if((l + x - 1) / x + 1 <= r / x) ans = max(ans, x);
    };

    for(int i = 1; i <= N; i++) {
        isok(i);
        isok(r / i);
    }    

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}