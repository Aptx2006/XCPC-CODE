#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = unsigned long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

/*
i t:
bi(0) * t
....
第j天 bi += x -> x * (t - j)
ai(t) = ai(0) + t * bi(0) + sum_{(t - j) * x}
111111
qry(l, r) = sum_{ai(0)} + t * sum_{bi(0)} + sum_{t*x} - sum_{j*x}
*/

struct BIT {
    vector<i64> a, b;
    int n;

    BIT(int n) : n(n), a(n + 1), b(n + 1) {}
    void rangeAdd(int l, int r, i64 val) { 
        auto add = [&](int pos, i64 val) {
            for (int i = pos; i <= n; i += i & -i) {
                a[i] += val;
                b[i] += pos * val;
            }
        };
        add(l, val), add(r + 1, -val);
    }
    i64 rangeSum(int l, int r) { 
        auto sum = [&](int x) {
            i64 ans = 0;
            for (int i = x; i; i -= i & -i) {
                ans += (x + 1) * a[i] - b[i];
            }
            return ans;
        };
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    cin >> n >> m;
    vector<i64> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    vector<i64> prea(n + 1), preb(n + 1);
    for(int i = 1; i <= n; i++) {
        prea[i] = prea[i - 1] + a[i];
        preb[i] = preb[i - 1] + b[i];
    }
    BIT bit1(n), bit2(n);
    for(i64 i = 1; i <= m; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) {
            i64 x;
            cin >> x;
            bit1.rangeAdd(l, r, x);        
            bit2.rangeAdd(l, r, x * i); 
        } else {
            i64 ans = (prea[r] - prea[l - 1]) + i * (preb[r] - preb[l - 1]) + i * bit1.rangeSum(l, r)- bit2.rangeSum(l, r);
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
