#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    i64 sum = n * (n + 1) / 2;
    
    auto isok = [&](i64 x) {
        i64 s = sqrt(x);
        if(s * s == x) return true;
        return false;
    };

    if(isok(sum)) {
        cout << -1 << '\n';
        return;
    }

    vector<int> p(n);
    iota(all(p), 1);

    for(int i = 1; i < n; i++) {
        i64 pre = 1ll * i * (i + 1) / 2;
        if(isok(pre)) swap(p[i - 1], p[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
