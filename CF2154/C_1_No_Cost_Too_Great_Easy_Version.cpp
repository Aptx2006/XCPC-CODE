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
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
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
        map<int,int>mp;
        int f = 0;
        auto mn = [&](int x){
            map<int,int>mp2;
            for(int i=2;i*i<=x;i++){
                if(x%i==0) {
                    mp2[i]++;mp2[x/i]++;
                    if(mp.count(i) or mp.count(x/i)) {
                        f = 1;
                    }
                }    
            }
            if(x!=1) {
                mp2[x]++;
                if(mp.count(x)) f = 1;
            }
            mp.insert(all(mp2));
        };
        forrr(n) {
            mn(ar[i]);
        }
        if(f){
            cout<<"0\n";return;
        }
        forrr(n){
            if(mp.count(ar[i]+1)){
                cout<<"1\n";return;
            }
            for(int j=2;j*j<=ar[i]+1;j++){
                if((ar[i]+1)%j==0){
                    if(mp.count(j) or mp.count((ar[i]+1)/j)){
                        cout<<"1\n";return;
                    }
                }
            }
        } 
    }
    cout<<"2\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
