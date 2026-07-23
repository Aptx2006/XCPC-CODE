#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    int x;
    cin >> n >> k >> x;
    vector<i64> a(n), pos(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    i64 d = x - a[k];
    for(int i = 0 ; i < n; i++) {
        cout << (a[i] + d + n) % n << " \n"[i == n - 1];
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
