#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    string s;
    cin >> s;
    n = s.size();
    int mask = 0;
    for(int i = 0; i < n - 1; i++) {
        string cur = s.substr(i, 2);
        if(cur == "00") mask |= 1;
        else if(cur == "01") mask |= 2;
        else if(cur == "10") mask |= 4;
        else if(cur == "11") mask |= 8;
    }
    cnt  = __builtin_popcount(mask);
    if(cnt < 4) {
        cout << cnt + 1 << '\n';
    }else {
        int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
        string p1 = "00110", p2 = "01100", p3 = "11001", p4 = "10011";
        for(auto c : s) {
            if(i1 < 5 and c == p1[i1]) i1++;
            if(i2 < 5 and c == p2[i2]) i2++;
            if(i3 < 5 and c == p3[i3]) i3++;
            if(i4 < 5 and c == p4[i4]) i4++;
        }
        if(max({i1, i2, i3, i4}) == 5) cout << "5\n";
        else cout << "6\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
