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
    int x = k - n + 1;
    if(1 > x or x > n) { 
        cout << "-1\n"; 
        return; 
    }
    vector ans(n, vector<int>(n));
    ans[0][0] = 1;
    int t = 2;
    for(int i = 1; i < x; i++) {
        ans[0][i] = t++;
        ans[i][0] = t++;
    }
    for(int i = x; i < n; i++) {
        ans[i][i] = t++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!ans[i][j]) {
                ans[i][j] = t++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
