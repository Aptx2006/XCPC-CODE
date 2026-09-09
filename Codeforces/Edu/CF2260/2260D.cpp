#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, cnt, ans;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    if(s[0] == '0' or s.find("00") != string::npos) {
        cout << "-1\n";
        return;
    }
    bool one = true;
    int len = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            if (~len & 1) {
                one = false;
            }
            len = 0;
        } else {
            if (i > 0 and s[i - 1] != '0' and s[i - 1] != s[i]) {
                one = false;
            }
            len++;
        }
    }
    if (one) {
        cout << "1\n";
        return;
    }
    if (s.find("+--+") == string::npos and s.find("-++-") == string::npos) {
        cout << "2\n";
        return;
    }
    cout << 3 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}