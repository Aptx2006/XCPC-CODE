#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, cnt;

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    cnt = count(all(a), 0);
    if(cnt < 2) cout << "-1\n";
    else {
        cout << int(a[0] == 1) + int(a.back() == 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}