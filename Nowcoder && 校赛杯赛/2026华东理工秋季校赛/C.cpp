#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
const int INF = 1e9;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(n);

    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    vector<int> v(all(a));
    v.insert(v.end(), all(b));
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    auto check = [&](int x) {
        array<vector<int>, 2> dp_a, dp_b;
        dp_a[0].assign(n, 0);
        dp_a[1].assign(n, -INF);

        dp_b[0].assign(n, 0);
        dp_b[1].assign(n, -INF);

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                dp_a[0][i] = 0;

                if(a[i] >= x) {
                    dp_a[1][i] = 1;
                }
            } else {
                dp_a[0][i] = max(dp_a[0][i - 1], dp_a[1][i - 1]);

                if(a[i] >= x) {
                    dp_a[1][i] = dp_a[0][i - 1] + 1;
                }
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            if(i == n - 1) {
                dp_b[0][i] = 0;

                if(b[i] >= x) {
                    dp_b[1][i] = 1;
                }
            } else {
                dp_b[0][i] = max(dp_b[0][i + 1], dp_b[1][i + 1]);

                if(b[i] >= x) {
                    dp_b[1][i] = dp_b[0][i + 1] + 1;
                }
            }
        }

        for(int k = 0; k <= n; k++) {
            int cur = 0;

            if(k == 0) {
                cur = max(dp_b[0][0], dp_b[1][0]);
            } else if(k == n) {
                cur = max(dp_a[0][n - 1], dp_a[1][n - 1]);
            } else {
                cur = max(
                    dp_a[0][k - 1] + max(dp_b[0][k], dp_b[1][k]),
                    dp_a[1][k - 1] + dp_b[0][k]
                );
            }
            if(cur >= m) return true;
        }

        return false;
    };

    int l = 0, r = v.size() - 1;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(v[mid])) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << v[ans] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
