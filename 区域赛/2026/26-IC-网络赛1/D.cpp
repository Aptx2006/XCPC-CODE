#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

const int mod = 998244353;

void solve() {
    cin >> n;
    vector<int> c(n + 1);
    i64 sum = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        c[x]++;
        sum += x;
    }

    int a = 0;
    while (1LL * a * (n - a) != sum) a++;

    i64 res = 1;
    int now = 0;
    for (int i = 0; i < a; i++) {
        if (now == i) res = res * 2 % mod;
        now += c[i];
        c[i] = 0;
        c[now]--;
    }
    if (now == a && c[a]) res = res * 2 % mod;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
