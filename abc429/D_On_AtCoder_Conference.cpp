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
int n, m, t, ar[MAXN], ans, cnt, k, c;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() { 
    cin >> n >> m >> c;
    vector<int> a(n);
    for (auto &x:a) cin >> x;
    sort(all(a));
    vector<int>aa,mp;
    if (n > 0) {
        int curr = a[0];
        cnt = 1;
        forrr(n-1) {
            if (a[i] == curr) {
                cnt++;
            } else {
                aa.pb(curr);
                mp.pb(cnt);
                curr = a[i];cnt = 1;
            }
        }
        aa.pb(curr);mp.pb(cnt);
    }
    int k = aa.size();
    vector<int>A,Mp;
    for (int i = 0; i < k; ++i) {
        A.pb(aa[i]);Mp.pb(mp[i]);
    }
    for (int i = 0; i < k; ++i) {
        A.pb(aa[i] + m);Mp.pb(mp[i]);
    }
    vector<int>pre;
    pre.pb(0);
    for (auto x : Mp)  pre.pb(pre.back()+x);
    set<int> p = {0, m};
    for (auto x : aa)  p.insert(x);
    vector<int> pos(all(p));
    ans = 0;
    for (int i=0; i<pos.size()-1;i++) {
        int L=pos[i],R=pos[i + 1];
        if (L >= m) break;
        R = min(R, m);
        if (L >= R) continue;
        R--;
        int len = R - max(L,0ll) + 1;
        int p = lower_bound(all(A), L - 1) - A.begin();
        int tag = pre[p] + c;
        auto it = lower_bound(pre.begin() + p + 1, pre.end(), tag);
        int q = (it != pre.end()) ? (it - pre.begin()) : pre.size();
        ll sum = pre[q] - pre[p];
        bool g = true;
        if (q > 0 and q - 1<A.size()) {
            if (A[q- 1] < R)  g = 0;
        }
        if (g) {
            ans += sum * len;
        } else {
            int RR = min(A[q - 1], R);
            RR = min(RR-1, R);
           int leftsum = (RR > L && RR >= max(L,0ll)) ? (RR - max(L,0ll) + 1) : 0;
            ans += sum * leftsum;
            int qq = min(q + 1,(int)pre.size());
            ans += (pre[qq] - pre[p]) * (len - leftsum);
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1;// cin >> times;
    while (times--) solve();
    return 0;
}
