#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    
    int g = __gcd(n, k);
    vector<int> c(g, 0);
    for (int i = 0; i < n; i++) {
        c[i % g] ^= (s[i] - '0');
    }

    bool ok = 1;
    for (int i = 0; i < g; i++) {
        int j = g - 1 - i;
        if (i != j) {
            if (c[i] != c[j]) {
                ok = false;
                break;
            }
        } else if (~n & 1){
            if (c[i] != 0) {
                ok = 0;
                break;
            }
        }
    }
    
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
