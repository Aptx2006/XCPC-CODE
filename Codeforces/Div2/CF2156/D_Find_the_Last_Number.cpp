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
#define range(L, R) for(int j=L;j!=R;(R>L?j++:j--))
//#define endl "\n"
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
const int B = 15;// 2^15 32768
void solve() { 
    cin >> n;
    auto ask = [&](int i, int x) {
        cout << "? " << i << ' ' << x << endl;
        cin >> t;if(t==-1) exit(0); 
        return t;
    };
    vector<int> may(n),ok(n-1);
    iota(all(may),1);iota(all(ok),1);
    while(may.size()!=1) {
        int good = -1,mn = 2e18;
        range(0, B) {
            cnt = 0;
            for(auto x : may) {
                if(x&(1<<j)) ++cnt;
            }
            if(!cnt or cnt==may.size()) continue; //all 0 all 1
            int diff = llabs(cnt - may.size()/2);
            if(diff<mn) {
                mn = diff,good = j;
            }
        }
        if(good==-1)
            range(0,B) {
                cnt = 0;
                for(auto x : may) {
                    if(x&(1<<j)) ++cnt;
                }if (cnt > 0 and cnt < may.size()) {
                    good = j;break;
                }
            }
        int mask = 1ll << good; m = ok.size();
        vector<int> tmp(m); 
        range(0,m) {
            tmp[j]=ask(ok[j], mask);
        }
        int c1=0,c2=0;
        for(auto b : tmp) if(b) ++c1;
        for(auto b : may) if(b & mask) ++c2;
        vector<int> mayy,okk;
        t = (c1!=c2);
        for(auto b : may) 
            if((b & mask)==t) mayy.pb(b);
        range(0,m) {
            if (tmp[j] == t)
                okk.pb(ok[j]);
        }
        may = mayy,ok = okk;
    }
    cout << "! " << may[0] << endl;
    return;
}

signed main() {
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
