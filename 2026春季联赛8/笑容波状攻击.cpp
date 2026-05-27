#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    string s;
    cin >> s;
    i64 n = s.size();

    i64 c0 = 0, c1 = 0;
    for(int i = 0; i < n; ) {
        int j = i;
        while(j < n and s[j] == s[i]) j++;
        i64 len = j - i;
        i64 sub = len *(len + 1) / 2;
        if(s[i] == '0') c0 += sub;
        else c1 += sub;
        i = j;
    }

    i64 sum = n * ( n + 1) / 2;
    i64 res = c0 + 2 *(sum - c0 - c1);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
