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
//#define int long long
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, m, t, ar[MAXN], ans, cnt, k;
void dxy(int &x, int &y, point p) { x = p.first, y = p.second; }
void solve() { 
    string s , ts;
    cin >> s >> ts;
    vector<int> mp1(30, 0), mp2(30, 0);
    for(auto &x : s) mp1[x-'a']++;
    for(auto &x : ts) mp2[x-'a']++;
    for(auto &x : s) {
        if(mp2[x-'a'] < mp1[x-'a']) {
            cout << "Impossible\n";
            return;
        }
    } 
    string res = "", res2 = "";
    for(int i = 0; i < 26; i++) {
        string add(mp2[i] - mp1[i], (char)(i+'a'));
        res += add;
    }
    int i = 0, j = 0;
    while(i < s.size() and j < res.size()) {
        if(s[i] <= res[j]) {
            res2 += s[i++];
        }else res2 += res[j++];
    }
    while(i < s.size()) res2 += s[i++];
    while(j < res.size()) res2 += res[j++];
    cout << res2 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
