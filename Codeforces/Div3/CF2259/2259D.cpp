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
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    cnt = count(all(a), 0);
    if(cnt == 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if(cnt == 0) {
        cout << string(n, 'A') << '\n';
        return;
    }

    string res(n, 'C');
    bool f = true;

    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            if(f) {
                res[i] = 'A';
                f = false;
            } else {
                res[i] = 'B';
            }
        }
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}