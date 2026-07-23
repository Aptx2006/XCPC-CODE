#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int MOD = 1e9 + 7;
i64 ca, cm, cc, cac, ccm;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    i64 ans = 0;
    ca = cm = cc = cac = ccm = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] >= 'a' && s[i] <= 'm') {
            if(s[i] == 'a') {
                ca++;
                cac += cc;
                ans += ccm;
            }else if(s[i] == 'c') {
                cc++;
                ccm += cm;
            }else {
                cm++;
            }
        }else {
            if(s[i] == 'A') {
                ca++;
            }else if(s[i] == 'C') {
                cc++;
                cac += ca;
            }else {
                cm++;
                ccm += cc;
                ans += cac;
            }
        }
        ans %= MOD;
        cout << ans << " \n"[i==n-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}