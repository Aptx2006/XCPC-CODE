#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, ans = 0;
    cin >> n >> m;
    while(n--) {
        int p, q, w;
        cin >> p >> q >> w;
        int need = (m*p + q - 1) / q;
        if(w < need) ans += need - w;
    }
    cout << ans << '\n';
}