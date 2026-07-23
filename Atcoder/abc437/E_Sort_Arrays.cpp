#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
#define int long long

const int MAXN = 3E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ans, cnt, k;
int x[MAXN], y[MAXN];

int fa[MAXN];

int find(int i){
    if(fa[i] == i) return i;
    return fa[i] = find(fa[i]);
}

bool dfs(int a,int b) {
    a = find(a);
    b = find(b);

    if(a + b == 0) return 0;
    if(!a) return 1;
    if(!b) return 0;
    if(y[a] != y[b]) return y[a] < y[b];

    int pa = find(x[a]), pb = find(x[b]);
    if(pa != pb) {
        if(dfs(pa, pb)) fa[b] = a;
        else fa[a] = b;
    }
    return dfs(x[a], x[b]);
}

void solve() { 
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        fa[i] = i;
    }
    vector<int> p(n);
    iota(all(p), 1);
    sort(all(p), [](auto o1, auto o2){
        if(dfs(o1, o2)) return true;
        if(dfs(o2, o1)) return false;
        return o1 < o2;
    });
    for(auto &x : p) cout << x << ' ';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;// cin >> times;
    while (times--) solve();
    return 0;
}
