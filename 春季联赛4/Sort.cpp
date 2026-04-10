#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<int> a(m);
    for(auto &x: a) cin >> x;
    int mn = *min_element(all(a)), f = 1;
    n--;
    while(n--) {
        for(auto &x: a) cin >> x;
        int k = 1e9;
        for(int i = 0; i < m; i++) 
            if(a[i] > mn) {
                k = min(k, a[i]);
            }
        if(k == 1e9) {
            f = 0;
        }
        mn = k;
    }
    cout << (f ? "YES\n": "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
