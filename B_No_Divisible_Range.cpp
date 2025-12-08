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
//#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() { 
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> pre(n+1, 0);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i-1];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            int sum = pre[i] - pre[j-1], f = 1;
            //debug(sum)
            for(int k = j; k <= i; k++) {
                if(sum % a[k-1] == 0) {
                    f = 0;
                    break;
                }
            }
            ans += f;
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;// cin >> times;
    while (times--) solve();
    return 0;
}
