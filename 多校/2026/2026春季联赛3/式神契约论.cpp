#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define dbg(A) cout << #A << ': ' << A << endl;

const int N = 2e5 + 5;
int n, m, k;

void solve() {
    cin >> n >> k;
    vector<int> ans(n + 1, 1);
    ans[1] = n - 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 2 * i; j <= n; j += i) {
            ans[i]++, ans[j]++;
        }
    }
    sort(ans.begin() + 1, ans.end(), greater<int>());
    cout << ans[k] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
