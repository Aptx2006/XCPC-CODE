#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

using P = pair<i64, i64>;

const int N = 3e5 + 5;
const i64 INF = 4e18;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int n, m;

void solve() {
    cin >> n;
    vector<int> a(2 * n), fa(n + 1);
    for(auto &x: a) cin >> x;
    iota(all(fa), 0);

    auto find = [&](int x) {
        while(x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    };
    auto merge = [&](int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return false;
        fa[v] = u;
        return true;
    };

    string ans(2 * n, '(');
    for(int i = 0; i < 2 * n; i += 2) {
        ans[i + 1] = ')';
        merge(a[i], a[i + 1]);
    }
    for(int i = 1; i + 1 < 2 * n; i += 2) {
        if(merge(a[i], a[i + 1])) {
            swap(ans[i], ans[i + 1]);
        }
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;cin>>T;
    while(T--) solve();
    return 0;
}