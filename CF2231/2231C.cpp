#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

i64 T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            v.push_back({1, 0});
            v.push_back({2, 1});
        }else {
            int c = 0;
            while(x > 1) {
                v.push_back({x, c});
                if (x & 1) x++;
                else x >>= 1;
                c++;
            }
            v.push_back({1, c});
        }
    }

    sort(all(v));

    ans = (1LL << 60);

    for(int l = 0, r; l < (int)v.size(); l = r) {
        r = l;
        i64 s = 0;

        while(r < (int)v.size() and v[r].first == v[l].first) {
            s += v[r].second;
            r++;
        }

        if(r - l == n) ans = min(ans, s);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
