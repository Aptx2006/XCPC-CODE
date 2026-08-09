#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    int len = s.size();
    i64 ans = 0;
    deque<int> dq;
    for(int i = len - 1; i >= 0; i--) {
        if(s[i] == '1') {
            dq.push_back(i + 1);
        }else {
            if(!dq.empty()) dq.pop_front();
            ans += i + 1;
        }
    }
    while(!dq.empty()) {
        ans += dq.back();
        dq.pop_back();
        if(dq.empty()) break;
        dq.pop_front();
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
