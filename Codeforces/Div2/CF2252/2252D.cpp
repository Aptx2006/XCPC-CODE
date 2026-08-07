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
    for(auto &x: a) cin >> x;
    vector<i64> d(n - 1);
    for(int i = 0; i < n - 1; i++) {
        d[i] = a[i + 1] - a[i];
    }
    int i = 0;
    while(i < n - 1) {
        int j = i;
        while(j < n - 1 and (d[j] & 1) == (d[i] & 1)) {
            j++;
        }
        sort(d.begin() + i, d.begin() + j);
        i = j; 
    }
    cout << a[0] << ' ';
    i64 cur = a[0];
    for(int i = 0; i < n - 1; i++) {
        cur += d[i];
        cout << cur << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
