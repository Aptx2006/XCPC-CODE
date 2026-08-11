#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> k;
    if(k < n or k > n * n) {
        cout << "-1\n";
        return;
    }
    if((k & 1) != (n & 1)) {
        cout << "-1\n";
        return;  
    }
    string ans(2 * n, ' ');
    int l = 0, r = 2 * n - 1, nn = n;
    while(nn > 0) {
        if(k >= 3 * nn - 2) {
            ans[l++] = '(';
            ans[r--] = ')';
            k -= (2 * nn - 1);
        } else {
            ans[l++] = '(';
            ans[l++] = ')';
            k--;
        }
        nn--;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
