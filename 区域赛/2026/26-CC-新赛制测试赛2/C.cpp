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
    cin >> n;
    vector<i64> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    priority_queue<i64> q;
    i64 sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        q.push(b[i]);
        while(sum < 0) {
            if(q.empty() or q.top() == 0) {
                cout << -1 << '\n';
                return;
            }
            sum += q.top();
            q.pop();
            ans++;
        }
    }
    cout << ans << '\n';

}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
