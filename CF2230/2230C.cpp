#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i64> a(n);
    i64 f = 0;
    vector<i64> b;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] >= 2) {
            b.push_back(a[i]);
        }else if(a[i] == 1) {
            f++;
        }
    }
    
    i64 ans = 0;
    if(b.empty()) {
        ans = 0;
    }else if (b.size() == 1) {
        ans = b[0] + min(f, b[0] / 2);
    }else {
        i64 add = 0, cur = 0;
        for(auto x : b) {
            add += x, cur += (x - 2) / 2;
        }
        ans = add + min(f, cur);
    }
    
    if(ans < 3) ans = 0;
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
