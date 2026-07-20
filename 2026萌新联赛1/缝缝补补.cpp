#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    i64 d = a[1] - a[0], ans = 0;
    for(int i = 1; i < n; i++) {
        i64 ai = a[0] + i * d;
        ans = __gcd(ans, llabs(ai - a[i]));
    }
    cout << (ans? ans: -1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}