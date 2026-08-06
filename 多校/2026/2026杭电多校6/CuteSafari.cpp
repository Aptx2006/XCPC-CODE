#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    if(s == t) {
        cout << "Yes\n";
        return;
    }
    if(n < 2 * k) {
        swap(s[0], s[n - 1]);
        if(s == t) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    auto fun = [&](string ss) {
        char a = ss[0], b = ss[n - 1];
        if(a > b) swap(a, b);
        char c = ss[k - 1], d = ss[k];
        if(c > d) swap(c, d);
        pair<char, char> p1 = {a, b}, p2 = {c, d};
        if(p1 > p2) swap(p1, p2);
        vector<char> res{p1.first, p1.second, p2.first, p2.second};
        return res;
    };
    if(n == 2 * k) {
        for(int i = 0; i < n; i++) {
            if(i != 0 and i != n - 1 and i != k - 1 and i != k) {
                if(s[i] != t[i]) {
                    cout << "No\n";
                    return;
                }
            }
        }
        if(fun(s) == fun(t)) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
  
    int cnt[26]{0};
    for(int i = 0; i < n; i++) {
        if(i == 0 or i == n - 1 or(i >= k - 1 and i <= n - k)) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }else {
            if(s[i] != t[i]) {
                cout << "No\n";
                return;
            }
        }
    }
  
    for(int i = 0; i < 26; i++) {
        if(cnt[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
