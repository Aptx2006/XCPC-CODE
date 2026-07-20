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
    i64 g = 0;
    for(int i = 1; i < n; i++) {
        g = __gcd(g, llabs(a[i] - a[0]));
    }
    if(g == 1) {
        cout << "-1\n";
        return;
    }
    vector<i64> out{g};
    for(i64 i = 2; i * i <= g; i++) {
        if(g % i != 0) {
            continue;
        }
        out.push_back(i);
        out.push_back(g / i);
    }
    sort(all(out));
    out.erase(unique(all(out)), out.end());
    for(auto &x: out) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}