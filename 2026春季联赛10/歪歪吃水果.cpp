#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    i64 n, m, a, b;
    cin >> a >> b >> n >> m;
    i64 k = n / m;
    k = k * k;
    //dbg(k)
    if(min(a, b) < k) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
