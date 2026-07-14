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
    if(n < 97) cout << "No\n";
    else {
        int k = n / 97;
        string ans(k, 'a');
        int add = n - k * 97;
        for(int  i = 0; i < k; i++) {
            if(add > 25) {
                ans[i] = 'z';
                add -= 25;
            }else{
                ans[i] = ans[i] + add;
                add = 0;
                break;
            }
        }
        if(add) {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
}
