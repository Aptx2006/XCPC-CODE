#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 n, m, d, l;

void solve() {
    cin >> n >> d >> l;
    i64 ans1 = 1, x = l - d;
    if(x > 0) { 
        i64 a = max(0ll, (x - n + d - 1) / d); 
        ans1 = a * n + max(1ll, x - a * d); 
    }
    i64 ans2 = n * (l - n - 1) + 1; 
    cout << ans1 << " " << ans2 << "\n";
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