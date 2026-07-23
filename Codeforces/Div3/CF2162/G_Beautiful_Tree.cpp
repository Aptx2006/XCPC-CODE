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
    cin >> n;
    if(n == 2) {
        cout<<"-1\n";return;
    }
    int sum =n*(n + 1)/2 , k = -1;
    forrr(n){
        int s = i * (sum - i);
        int r = (int)(sqrtl(s) + 0.5);
        if (r * r == s) {
            k = i;
            break;
        }
    }
    if(k != -1) {
        forrr(n) {
            if (i != k) cout<<i<<' '<<k<< endl;
        }return;
    }
    m = sqrtl((sum-1));
    if(m * m + 1 < sum) m++;
    while (1) {
        int tag = m * m;
        int d = tag - (sum-1);
        if(d==1 or d==2 or d>sum-3) {
            m++;continue;
        }
        vector<int>v;
        if(d>n) {
            int r=d-n;
            if(r==0) {
                v.pb(n);
            }else if(r==1) {
                v.pb(n-2),v.pb(3);
            }else if (r==2) {
                v.pb(n-1),v.pb(3);
            }else v.pb(n),v.pb((int)r);
        }else if (d>=3 and d<=n) {
            v.pb(d);
        }else {
            m++;continue;
        }
        vector<int>mp(n+1);
        for(auto x:v)mp[x]++;
        for (int j=2; j<=n; j++) if (!mp[j]) cout<<j<<' '<<1<<endl;
        for (auto x:v) cout << 2 <<' '<<x<< endl;
        return;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;cin >> times;
    while (times--) solve();
    return 0;
}
