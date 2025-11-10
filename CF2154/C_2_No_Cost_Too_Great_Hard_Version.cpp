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
#define forrr(A) for(int i = 1; i <= A; i++)
#define range(s, e) for (int j = s; j <= e; j++)
#define endl "\n"
#define debug(A) cout << #A << "==" << A << "\n";
#define pb push_back
#define point pair<int, int>
#define all(A) A.begin(), A.end()
#define eps(A) fixed << setprecision(A)
#define nextp(A) next_permutation(A.begin(), A.end())
#define int long long
const int MAXN = 2e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
vector<int>spilt(int x) {
    vector<int>res;
    for(int i=2;i*i<=x;i++) {
        if (x%i==0) {
            res.pb(i);
            while (x%i==0) x/=i; 
        }
    }
    if(x>1) res.pb(x); 
    return res;
}
void solve() { 
    cin >> n;
    forrr(n) cin >> ar[i];
    vector<int>b(n+1);
    forrr(n) cin >> b[i];
    cnt = 0;
    forrr(n) cnt += (~ar[i]&1);
    if(cnt>=2){
        cout<<"0\n";return;
    }else{
        set<int> pri;
        forrr(n) {
            for (int p:spilt(ar[i])) pri.insert(p);
            for (int p:spilt(ar[i] + 1)) pri.insert(p);
        }
        ans = LLONG_MAX;
        for (int p : pri) {
            vector<int>costs;
            forrr(n) {
                int rem=ar[i] % p;
                k=(p-rem) % p; 
                costs.pb(k * b[i]); 
            }
            int c1=LLONG_MAX,c2=LLONG_MAX;
            for (int c : costs) {
                if (c < c1) {
                    c2=c1,c1=c;
                } else if (c < c2) {
                    c2=c;
                }
            }
            ans=min(ans,c1+c2);
        }
        cout << ans << endl;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
