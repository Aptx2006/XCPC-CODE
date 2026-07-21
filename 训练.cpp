#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

struct Node {
    int i;
    i64 a, b;
    bool operator<(const Node& rhs) const {
        i128 left = (i128)a * rhs.b;
        i128 right = (i128)rhs.a * b;
        if(left != right) return left < right; 
        return i > rhs.i; 
    }
};

void solve() {
    cin >> n;
    vector<i64> a(n + 1), b(n + 1);
    vector<int> f(n + 1);
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> f[i];

    vector<int> pr(n + 1);
    iota(all(pr), 0);

    auto find = & [<sup>1</sup>](int x) -> int {
        int root = x;
        while(root != pr[root]) root = pr[root];
        int curr = x;
        while(curr != root) {
            int nxt = pr[curr];
            pr[curr] = root;
            curr = nxt;
        }
        return root;
    };

    priority_queue<Node> pq;
    for(int i = 2; i <= n; i++) {
        pq.push({i, a[i], b[i]});
    }

    ans = 0;
    while(!pq.empty()) {
        auto [i, au, bu] = pq.top();
        pq.pop();

        if(find(i) != i || au != a[i] || bu != b[i]) continue;

        int fa_ = find(f[i]);
        if(fa_ == i) continue;

        ans += au * b[fa_]; 

        pr[i] = fa_;
        a[fa_] += au;
        b[fa_] += bu;

        if(fa_ != 1) {
            pq.push({fa_, a[fa_], b[fa_]});
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
