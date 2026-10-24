#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m;
const vector<int> v = {0, 1, 2, 3};
void solve() {
    cin >> n;
    string s[4];
    vector<int> cnt(4), ans(4, 2000), flag(4, 0);
    for(int i: v) {
        cin >> s[i];
        //cout << s[i] << endl;
    }
    
    auto duel = [&](int i) {
        if(ans[i] >= 2000) ans[i] = 2000;
        if(ans[i] <= 0) ans[i] = 0, flag[i] = 1;
        if(flag[i]) ans[i] = 0;
    };
    for(int i = 0; i < n; i++) {
        //cout << "    " << i << " " << s[0][i];
        for(int j: v) {
            if(i != 0 and s[j][i] == s[j][i - 1] and s[j][i] == 'H') {
                cnt[j]++;
            }else if(s[j][i] == 'H'){
                cnt[j] = 1;
            }else {
                cnt[j] = 0;
            }
            if(cnt[j] == 100) {
                cnt[j] = 0;
                for(int k: v) {
                    if(k == j) continue;
                    ans[k] += 30;
                }
            }
            //cout << "\t" << s[j][i] << ' ' <<  ans[j] << endl;
            if(s[j][i] == 'H' or s[j][i] == 'C') {

            }else if(s[j][i] == 'J') {
                ans[j] -= 50;
            }else if(s[j][i] == 'A') {
                ans[j] -= 100;
            }else if(s[j][i] == 'M') {
                ans[j] -= 200;
            }
            //cout << "\t" << i;
            //cout << "\t" << ans[j];
            //cout << "\t" << ans[j] << endl;
        }
        for(int k: v) {
            duel(k);
        }
    }
    for(int i: v) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
}