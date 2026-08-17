#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<string> a(n);
    vector<bool> vis(30);
    for(auto &s: a) {
        cin >> s;
        char c = toupper(s[0]);
        vis[c - 'A'] = 1;
    }
    vector<string> b(m);
    bool ok = true;
    for(auto &s: b) {
        cin >> s;
        for(auto c: s) {
            if(!vis[c - 'A']) {
                ok = false;
            }
        }
    }

    if(ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
