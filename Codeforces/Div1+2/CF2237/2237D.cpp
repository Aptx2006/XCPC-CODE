#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, buc;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    vector<int> pre(n + 1, 0);
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') pre[i + 1] = pre[i] + 1;
        else pre[i + 1] = pre[i] - 1;
    }
    for(auto &x: pre) x = (x % 3 + 3) % 3;
    vector<i64> buc(3, 0);
    for(auto x : pre) buc[x]++;
    i64 sum = 0;
    for(int i = 0; i < 3; i++) {
        sum += buc[i] * (buc[i] - 1) / 2;
    }
    i64 sum_s = n * (n + 1) / 2;
    i64 ans = sum_s - sum, bad = 0;
    int st = 0;
    for(int i = 0; i < n; i++) {
        if(i == n - 1 or s[i] == s[i + 1]) {
            i64 L = i - st + 1;
            if(L >= 2) {
                i64 cnt0 = L / 2 + 1;          
                i64 cnt1 = (L + 1) - cnt0; 
                i64 same = cnt0 * (cnt0 - 1) / 2 + cnt1 * (cnt1 - 1) / 2;
                i64 sum_ = L *(L + 1) / 2;
                i64 ans_ = sum_ - same;
                bad += ans_ - L; 
            }
            st = i + 1;
        }
    }
    cout << ans - bad << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}