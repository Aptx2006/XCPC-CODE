#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    ans = 0;
    for(int i = 0; i < n; i += k) {
        bool f = false;
        for(int j = i; j < i + k; j++) {
            if(s[j] == '0') {
                f = true;
                break;
            }
        }
        if(!f) ans++;
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}