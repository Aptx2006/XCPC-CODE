#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
const int MOD = 998244353;

void solve() {
    string s;
    cin >> s;
    i64 cur = 0;
    for(auto c : s) {
        if(c >= '0' and c <= '9') cur = cur * 16 + (c - '0');
        else cur = cur * 16 + (c - 'A' + 10);
    }
    i64 sum = 0;
    for(auto c : s) {
        sum += (int)c;
    }
    i64 dif = cur - sum;
    if(dif == 0) {
        cout << s << "\n";
        return;
    }
    string cand = "FEDCBA9876543210";
    reverse(all(cand));
    vector<int> dp(dif + 1, -1);
    dp[0] = 0;
    for(int i = 0; i <= dif; i++) {
        if(dp[i] == -1) continue;
        for(int j = 0; j < 16; j++) {
            int v = (int)cand[j];
            if(i + v <= dif and dp[i + v] == -1) {
                dp[i + v] = j;
            }
        }
    }
    string add = "";
    while(dif > 0) {
        int id = dp[dif];
        add += cand[id];
        dif -= (int)cand[id];
    }
    cout << s + add << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (; T--; solve());
    return 0;
}
