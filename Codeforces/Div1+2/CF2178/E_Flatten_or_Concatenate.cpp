#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
#define int long long

// const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ans, cnt, k;

auto qry = [](int l, int r) {
    cout << "? "<< l << " " << r << endl;
    cin >> t;
    if(t == -1) exit(0);
    return t;
};   

void solve() { 
    cin >> n;
    //cout << "! " << dfs(1, n) << endl;    
    int l = 1, r = n;
    int sum = qry(l, r);
    while(l < r){
        int tag = sum / 2;
        int low = l, high = r;
        ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int csum = qry(l, mid);
            if(csum == tag) {
                ans = mid;
                break;
            }
            if(csum < tag) low = ++mid;
            else high = --mid;
        }   
        if(ans - l + 1 < r - ans) {
            r = ans;
        }else {
            l = ans + 1;
        }
        sum = tag;
    }         
    cout << "! " << sum << endl;                                                                                                                        
}

signed main() {
    //ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
