#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    if(a == b) {
        cout << "0\n";
        return;
    }
    bool f1 = 1, f2 = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            f1 = 0;
        }
        if(b[i] == 0) {
            f2 = 0;
        }
    }
    if(f1 or f2) {
        cout << "-1\n";
        return;
    }
    cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1 and b[i] == 0) {
            cnt++;
        }
    }
    cout << 2 - cnt % 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
