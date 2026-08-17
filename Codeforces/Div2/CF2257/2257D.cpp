#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k;

void solve() {
    i64 s, q;
    cin >> s >> q;
    vector<i64> div{0};
    for(i64 i = 1; i * i <= s; i++) {
        if(s % i == 0) {
            div.push_back(i);
            div.push_back(s / i);
        }
    }
    sort(all(div));
    div.erase(unique(all(div)), div.end());
    int n = (int)div.size() - 1;
    vector<i64> pre(n + 1);
    for(int i = 1; i <= n; i++) {
        i64 x = div[i] - div[i - 1];
        i64 y = s / div[i];
        pre[i] = pre[i - 1] + x * y;
    }

    auto calc = [&](i64 x) -> i64{
        if(x <= 0) return 0ll;
        int id = lower_bound(div.begin() + 1, div.end(), x) - div.begin();
        i64 A = pre[id - 1];
        i64 B = div[id - 1];
        i64 y = s / div[id];
        return A + (x - B) * y;
    };

    while(q--) {
        i64 x, y;
        cin >> x >> y;
        i64 lim = s / y;
        int id = upper_bound(div.begin() + 1, div.end(), lim) - div.begin() - 1;
        i64 ans = min(x, div[id]) * y;
        if(x > div[id]) {
            ans += calc(x) - calc(div[id]);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}

