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
#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() { 
    cin >> n;
    vector<int> a1,a0;
    forrr(n){ 
        cin >> t;//艺术般的三目运算法,ljm你就学吧
        (t&1?a1:a0).pb(t);
    }
    if(a0.size()>1){
        cout<<a0[0]<<' '<<a0[1]<<endl;
        return;
    }
    if(!a0.empty()){
        for(auto x:a1){
            int y = max(x,a0[0])%min(x,a0[0]);
            if(~y&1){
                cout<<min(x,a0[0])<<' '<<max(x,a0[0])<<endl;
                return;
            }
        }
    }
    m = a1.size();
    range(1,m){
        if(a1[j] < 2*a1[j-1]){
            cout<<a1[j-1]<<' '<<a1[j]<<endl;
            return;
        }
    }
    for(int i=0;i<m-1;i++){
        range(i+1,m){
            int y = a1[j]%a1[i];
            if(~y&1){
                cout<<a1[i]<<' '<<a1[j]<<endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
