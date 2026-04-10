#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
string pre, in;


int dfs(int l1, int r1, int l2, int r2) {
    if(l1 > r1) return 0;
    char root = pre[l1];
    int k = l2;
    while(k <= r2 and in[k] != root) k++;
    int lson = k - l2;
    int lh = dfs(l1 + 1, l1 + lson, l2, k - 1);
    if(lh < 0) return -1;
    int rh = dfs(l1 + lson + 1, r1, k + 1, r2);
    if(rh < 0) return -1;
    if(abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}

void solve() {
    cin >> pre >> in;
    int h = dfs(0, (int)pre.size() - 1, 0, (int)in.size() - 1);
    cout << (h >= 0 ? "True" : "False");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
