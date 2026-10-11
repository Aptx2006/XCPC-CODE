#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {

}

int main(int argc, char *argv[]) {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //for(; T--; solve());
    
    int id = atoi(argv[1]);
    if(id == 0) {
        cin >> n;
        vector<i64> a(n);
        for(auto &x: a) cin >> x;
        sort(all(a));
        cout << n << endl;
        for(auto x : a) {
            cout << x << ' ';
        }
        cout << endl;
        cin >> ans;
        cout << ans << endl;
    }else {
        cin >> n;
        vector<i64> b(n);
        for(auto &x: b) cin >> x;
        cin >> m;
        vector<i64> a(m);
        for(auto &x: a)  cin >> x;
        sort(all(b));
        int res = 1;
        if(n != m) {
            res = 0;
        }else {
            for(int i = 0; i < n; i++) {
                if(a[i] != b[i]) {
                    res = 0;
                    break;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
