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
    vector<int> b(n);
    for(int i = 1; i <= n; i++) {
        int x; 
        cin >> x;
        b[i - 1] = x - i;     
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end()); 
    ans = cnt = 1;
    for(int i = 1; i < (int)b.size(); i++) {
        if(b[i] == b[i-1] + 1) cnt++;
        else cnt = 1;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
