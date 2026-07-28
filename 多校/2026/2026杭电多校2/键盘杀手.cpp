#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
/*
i 被拔掉时，代价取决于ai-1和ai+1
如果其中某个已经被拔掉，则没有贡献
所以拔的顺序决定了贡献

对于任意 i 和 i + 1，它们被拔掉的先后顺序决定了谁对谁贡献了高度：
1. 如果 i 比 i + 1 先拔（向右）
    i 的代价和 ai+1 有关
    i + 1 的代价和 ai 无关
2. 如果 i 比 i + 1 后拔（向左）
    i 的代价和 ai+1 无关
    i + 1 的代价和 ai 有关

状态设计
dp1[i] 表示当 i 比 i + 1 后拔时，最小的代价，即此时只需要考虑左边
dp2[i] 表示当 i 比 i + 1 先拔时，最小的代价，两边都要考虑

对于dp1：
dp1[i] = max{dp1[i - 1] + a[i - 1], i - 1 比 i 后拔
            dp2[i - 1]}             i - 1 比 i 先拔

对于dp2：
dp2[i] = max{dp1[i - 1] + max(a[i - 1], a[i + 1]), i - 1 比 i 后拔
            dp2[i - 1] + a[i + 1]}                 i - 1 比 i 先拔
*/
void solve() {
    cin >> n;
    vector<i64> a(n + 2);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<i64> dp1(n + 5), dp2(n + 5, 2e18); 
    for(int i = 1; i <= n; i++) {
        dp1[i] = min(dp1[i - 1] + a[i - 1], dp2[i - 1]);
        dp2[i] = min(dp1[i - 1] + max(a[i - 1], a[i + 1]), dp2[i - 1] + a[i + 1]);
    }
    cout << dp2[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
