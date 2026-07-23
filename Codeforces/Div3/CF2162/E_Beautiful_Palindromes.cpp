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
//#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() { 
    cin >> n >> m;
    vector<int>s(n);
    for(auto &x:s) cin >> x;
    /*以位置i 为中心的
	最长回文串的半径长度（半径长度 𝑑1[𝑖] 𝑑2[𝑖]
	均为从位置i 到回文串最右端位置包含的字符个数）。*/
	vector<int> d1(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	vector<int> d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k;
		}
	}
    // for(auto x:d1) cout<<x<<' ';cout<<endl;
    // for(auto x:d2) cout<<x<<' ';cout<<endl;

    vector<int>dd;
    for(int i=0;i<n;i++){
        if(i+d1[i]==n){
            if(d1[i]<=i)
            dd.pb(s[i-d1[i]]);
        }
        if(i+d2[i]==n){
            if(i-d2[i]-1>=0)
            dd.pb(s[i-d2[i]-1]);
        }
    }dd.pb(s[n-1]);
    //for(auto x:dd) cout<<x<<" ";cout<<endl;
    auto get = [&](int x){
        if(x!=n) return x+1;
        else return x-1; 
    };
    vector<int>ss(n+m+5);
    for(int i=0;i<n;i++) ss[i] = s[i];
    if(dd.size()){
        vector<int>buc(n+1);cnt = 0;
        for(auto x:dd){
            if(buc[x]++==0) cnt++;
        }
        for(int i=1;i<=n;i++)
            if(!buc[i]){
                ss[n] = i;
            }
    }
    int f = 1;
    for(int i=n;i<n+m;i++){
        if(ss[i]!=0) continue;
        if(ss[i-1]==n or ss[i-1]==0) f=-f;
        ss[i] = ss[i-1] + f;
    }
    for(int i=n;i<n+m;i++) cout<<ss[i]<<" \n"[i==n+m-1];
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
