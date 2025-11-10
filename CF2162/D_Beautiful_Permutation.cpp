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
//#define endl "\n"
#define debug(A) cout << #A << "=" << A << " ";
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
    auto ask = [](int x,int r){
        cout<<x<<' '<<1<<' '<<r<<endl;
        cin >> t;return t;
    };
    k = n*(n+1)/2 - ask(2,n);
    int ans = n,l  = 1  ,r =n;
    auto isok = [&](int x){
        return ask(2,x) > ask(1,x);
    };
    while(l<=r){
        int mid = (l+r)>>1;
        if(isok(mid)){
            ans = mid, r = mid -1;
        }else l = mid + 1;
    }
    cout<<"! "<<ans<<' '<<ans-k-1<<endl;
    return;
}

signed main() {
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
