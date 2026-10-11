#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void A() {
    i64 L;
    cin >> n >> L;
    vector<i64> p(n);
    for(int i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        p[i] = a / L;
    }
    sort(all(p), greater<i64>());
    for(auto x : p)
        cout << x << ' ';
    cout << endl;
}

void B() {
    cin >> n >> k;
    vector<i64> p(n);
    for(auto &x: p) cin >> x;
    i64 sum = 0;
    for(int i = 0; i < n; i++) {
        sum += p[i];
        if(sum >= k) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

void solve() {
    int op;
    cin >> op;
    if(op == 1)
        A();
    else
        B();
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
