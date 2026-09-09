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

    int res = 0;
    auto ask = [&](int u, int v, int d){
        cout << "? " << u << ' ' << v << ' ' << d << endl;
        cin >> res;
        if(res == -1) exit(0);
        return res;
    };

    int st = 1, mx = 0;
    for(int i = 1; i <= n; i++) {
        while(ask(1, i, mx + 1) == 1) {
            mx++;
            st = i;
        }
    }

    int ed = 1;
    for(int i = 1; i <= n; i++) {
        while(ask(st, i, mx + 1) == 1) {
            mx++;
            ed = i;
        }
    }

    cout << "! " << st << ' ' << ed << ' ' << mx << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
