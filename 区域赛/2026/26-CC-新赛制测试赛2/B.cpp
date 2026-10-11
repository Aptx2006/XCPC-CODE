#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    i64 l = 0, r = 1e9;

    auto ask = [&](i64 x) {
        cout << "? " << x << endl;
        cin >> k;
    };

    auto answer = [&](i64 x) {
        cout << "! " << x << endl;
    };

    i64 ans = 0;
    while(l <= r) {
        i64 mid = (l + r) >> 1;
        ask(mid);
        if(k) {
            r = mid - 1;
            ans = mid;
        }else {
            l = mid + 1;
        }
    }
    answer(ans);
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
