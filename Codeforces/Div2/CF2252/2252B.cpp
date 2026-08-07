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

    int c0 = count(all(s), '0'), c1 = n - c0;
    
    if(abs(c0 - c1) > 2) {
        cout << -1 << "\n";
        return;
    }

    string tag = "";
    for(auto c : s) {
        if(tag.empty() or tag.back() != c) {
            tag += c;
        }
    }
    
    int len = tag.length();
    int b0 = count(all(tag), '0'), b1 = len - b0;
    int ans = -1;
    
    if(abs(c0 - c1 - 1) <= 1) {
        int cur = len;
        if(b0 - b1 != 1) { 
            if(b0 - b1 == 0) cur -= 1;       
            else if(b0 - b1 == -1) cur -= 2; 
        }
        ans = max(ans, cur);
    }
    if(abs(c0 - c1) <= 1) {
        int cur = len;
        if(b0 - b1 != 0) {
            cur -= 1; 
        }
        ans = max(ans, cur);
    }
    if(abs(c0 - c1 + 1) <= 1) {
        int cur = len;
        if(b0 - b1 != -1) {
            if(b0 - b1 == 0) cur -= 1;    
            else if(b0 - b1 == 1) cur -= 2; 
        }
        ans = max(ans, cur);
    }
    if(ans == -1) cout << -1 << "\n";
    else cout << n - ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
