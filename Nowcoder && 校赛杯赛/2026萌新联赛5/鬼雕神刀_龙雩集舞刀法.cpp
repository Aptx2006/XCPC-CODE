#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve(){
    int L, R;
    cin >> L >> R;
    vector<i64> a(R + 1, 0);
    for(int i = 1; i <= R; i++) {
        for(int j = i; j <= R; j += i) {
            a[j] += i;
        }
    }

    double ans = 0.0;
    for(int x = L; x <= R; x++) {
        double cur = a[x] * 1.0 / x;
        if (cur > ans) {
            ans = cur;
        }
    }

    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
