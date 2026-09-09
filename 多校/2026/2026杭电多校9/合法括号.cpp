#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    string s;
    cin >> s;
    int st = -1, len = 0;
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            if (st == -1) st = i;
            len++;
        } else if (s[i] == '(') c1++;
        else c2++;
    }

    if(len == 0) {
        cout << s << "\n";
        return;
    }

    int needl = n / 2 - c1;
    int needr = n / 2 - c2;

    int H0 = 0;
    for(int i = 0; i < st; i++) {
        if(s[i] == '(') H0++;
        else H0--;
    }

    for(int i = 0; i < needl; i++) s[st + i] = '(';
    for(int i = 0; i < needr; i++) s[st + needl + i] = ')';

    i64 base = 0, cur = 0;
    for(char c : s) {
        if (c == '(') cur++;
        else base += cur, cur--;
    }

    i64 dif = base - m; 
    vector<int> x(needr + 1, needl);
    for (int i = 1; i <= needr; i++) {
        int low = max(x[i - 1], max(0, i - H0)); 
        int mn = min((i64)(needl - low), dif);
        x[i] = needl - mn;
        dif -= mn;
    }

    string mid = "";
    int P = 0;
    for(int i = 1; i <= needr; i++) {
        while (P < x[i]) {
            mid.push_back('(');
            P++;
        }
        mid.push_back(')');
    }
    while(P < needl) {
        mid.push_back('(');
        P++;
    }

    for(int i = 0; i < len; i++) {
        s[st + i] = mid[i];
    }

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
