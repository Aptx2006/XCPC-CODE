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
    int mn = 1e9,mx = -1e9;
    forrr(n){
        cin >> t;
        mn = min(mn,t);
        mx = max(mx,t);
    }
    cin >> t;
    if(t<=mx and t>=mn){
        cout<<"Yes\n";
    }else cout<<"No\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;cin >> times;
    while (times--) solve();
    return 0;
}
