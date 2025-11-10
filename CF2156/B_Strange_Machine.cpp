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
#define range(s, e) for (int j = s; j <= e; j++)
#define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() { 
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int>Q(m);
    for (auto &x:Q) 
        cin >> x;
    for (int i=0; i<m; ++i) {
        int a = Q[i];
        if (s.find('B')==-1) {
            cout << a << endl;
            continue;
        }
        int pos = 0;ans = 0;
        while(a > 0) {
            if(s[pos]=='B') {
                a/=2;
                ++ans;
                if (++pos==n) pos = 0;
            }else{
                int c = pos,k = 0;
                while (s[c]=='A') {
                    ++k;
                    if (++c==n) c = 0;
                }if (a>k) {
                    a -= k,ans += k;
                    pos = c;
                } else {
                    ans += a,a = 0;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;cin >> times;
    while (times--) solve();
    return 0;
}
