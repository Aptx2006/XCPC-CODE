#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int sum13 = count(all(s), '1') + count(all(s), '3');
    int ans = sum13;
    int c2 = 0, c13 = sum13;
    
    for(char c : s) {
        if (c == '2') {
            c2++;
        } else if (c == '1' or c == '3') {
            c13--;
        }
        ans = max(ans, c2 + c13);
    }
    
    cout << n - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
