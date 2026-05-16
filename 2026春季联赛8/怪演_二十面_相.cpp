#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    string s;
    cin >> s;
    ans = 0;
    int r = 0, b = 0;
    for(char c: s) {
        if(c == 'W') {
            ans = max(ans, r + b);
            r = b = 0;
        } else if(c == 'R') {
            if(b) b--;
            r++;
        } else {
            if(r) r--;
            b++;
        }
    }
    cout << max({1, ans, r + b}) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
