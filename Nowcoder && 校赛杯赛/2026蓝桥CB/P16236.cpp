#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m, ans, cnt;

void solve() {
    string s;
    cin >> n >> s;
    ans = cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') cnt++;
        else {
            ans += cnt;
        }
    }
    int preL = 0, sufQ = n - cnt, add = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            preL++;
        }else if(s[i] == 'Q') {
            sufQ--;
        }else {
            sufQ--;
            if(preL < sufQ) {
                add += sufQ - preL;
                preL++;
            }else break;
        }
    }
    cout << ans + add << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}