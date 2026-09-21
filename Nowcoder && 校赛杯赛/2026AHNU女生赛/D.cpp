#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m;
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};

void solve() {
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    for(int i = 0; i <= n - 5; ) {
        if(s.substr(i, 5) == "istar") {
            cnt++;
            i += 5;
        }else {
            ans = max(ans, cnt);
            cnt = 0;
            i++;
        }
    }
    ans = max(ans, cnt);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
