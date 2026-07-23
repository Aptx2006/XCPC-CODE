#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

const i64 N = 2e5 + 5, M = 1e9 + 7;
i64 n, m, sum[2], have[2];
string s;
vector< pair<int, int> > ans;

void solve() {
    auto op1 = [&](const string &s) {
        string res = "";
        for(auto &x : s) 
            if(x == 'S') res += "0S1S";
            else res += x;
        return res;
    };

    auto op2 = [&](const string &s) {
        string res = "";
        for(auto &x : s) 
            if(x == 'S') res += "1S0S";
            else res += x;
        return res;
    };    
    
    cin >> s;
    n = s.size();
    if(n & 1 or count(s.begin(), s.end(), '1') != n/2) {
        cout << "-1\n";
        return;
    }

    int pos = 1;        
    for(int i = 0; i < n; i ++) {
        if(s[i] == '0') {
            if(++sum[0] > have[0]) {
                ans.push_back({pos, 1});
                have[0]++, have[1]++;
            } else pos++;
        } else {
            if(++sum[1] > have[1]) {
                ans.push_back({pos, 2});
                have[0]++, have[1]++;
            } else pos++;
        }
    }
    cout << ans.size() << '\n';
    for(auto &[x, y] : ans) cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while(T--) solve();
}
