#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    string s, ans;
    cin >> s;
    int ct1 = 0, ct2 = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '(') {
            ct1 += 1;
        }else {
            ct2 = min(ct2 + 1, ct1);
        }
    }
    if(ct1 == ct2) {
        cout << s << '\n';
    }else {
        cout << "impossible\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
