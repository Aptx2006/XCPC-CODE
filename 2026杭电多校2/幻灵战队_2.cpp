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
    string s;
    cin >> s;
    vector<i64> block;
    cnt = 0;
    for(auto &x: s) {
        if(x == '0') {
            cnt++;
        }else {
            block.push_back(cnt);
            cnt = 0;
        }
    }    
    block.push_back(cnt);

    auto calc = [&](i64 len) -> i64{
        if(len <= 0) return 0;
        return (45 + 5 * len) * len / 2;
    };

    auto fun = [&](i64 len, i64 p) -> i64{
        if(p >= len) return 0;
        i64 i = (len - p) / (p + 1), j = (len - p) % (p + 1);
        return j * calc(i + 1) + ((p + 1) - j) * calc(i);
    };

    i64 ans = 0, sum = 0;
    vector<i64> a;
    for(auto &len: block) {
        ans += calc(len);
        i64 mid = len / 2;
        for(int i = 0; i < mid; i++) {
            a.push_back(fun(len, i) - fun(len, i + 1));
        }
        sum += (len + 1) / 2;
    }

    sort(all(a), greater<i64>());
    i64 sz = a.size();

    for(int i = 0; i < min(sz, k); i++) {
        ans -= a[i];
    }

    if(k > sz) {
        ans -= min(k - sz, sum) * 25;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
