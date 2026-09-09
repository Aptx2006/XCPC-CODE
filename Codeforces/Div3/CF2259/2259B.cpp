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
    int odd = 0, mod0 = 0, mod2 = 0;  
    for(auto &x : a) {
        if(x & 1) {
            odd++;
        } else if (x % 4 == 0) {
            mod0++;
        } else {
            mod2++;
        }
    }

    cout << max({odd, mod0, mod2}) << '\n';
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}