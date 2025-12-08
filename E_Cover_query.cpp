#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
ui64: 0~1.8e19*/
typedef unsigned long long ull;
typedef unsigned long long ui64;
typedef long long i64;
typedef long long ll;
#define umap unordered_map
#define forrr(A) for (int i = 1; i <= A; i++)
#define range(s,e) for (int j=s;j!=e;(s<e?j++:j--))
#define endl '\n'
#define debug(A) cout << #A << "==" << A << '\n';
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, q, ans;

struct node {
    int l, r;
    node(int l_, int r_) : l(l_), r(r_) {}
    bool operator<(const node& rhs) const {
        return l < rhs.l;
    }
};

void solve() {
    cin >> n >> q;
    set<node> pos; 
    ans = 0;  
    while (q--) {
        int l, r;
        cin >> l >> r;
        int nl = l;
        int nr = r;
        auto it = pos.lower_bound(node(l, r));
        if (it != pos.begin()) {
            --it;
            if (it->r + 1 >= nl) { 
                nl = min(nl, it->l);
                nr = max(nr, it->r);
                ans -= (it->r - it->l + 1);
                it = pos.erase(it);
            } else {
                ++it; 
            }
        }

        while (it != pos.end() and it->l <= nr + 1) {
            nl = min(nl, it->l);
            nr = max(nr, it->r);
            ans -= (it->r - it->l + 1);
            it = pos.erase(it);
        }

        pos.insert(node(nl, nr));
        ans += (nr - nl + 1);

        cout << n - ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;// cin >> times;
    while (times--) solve();
    return 0;
}
