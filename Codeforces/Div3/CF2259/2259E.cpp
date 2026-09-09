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
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> dif(n + 1);

    for(int i = 0; i < n; i++) {
        if(a[i] <= 0) continue;
        int l = max(0, i - a[i] + 1);
        int r = min(n - 1, i + a[i] - 1);
        if(l <= r) {
            dif[l]++;
            dif[r + 1]--;
        }
    }

    string res(n, '0');
    int cur = 0;

    for(int i = 0; i < n; i++) {
        cur += dif[i];
        if (cur == 0) {
            res[i] = '1';
        }
    }

    vector<int> dis(n, 1e9);

    int last = -1;
    for(int i = 0; i < n; i++) {
        if(res[i] == '1') last = i;
        if(last != -1) dis[i] = i - last;
    }

    last = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(res[i] == '1') last = i;
        if(last != -1) dis[i] = min(dis[i], last - i);
    }
    if(res.find('1') == string::npos) {
        cout << "-1\n";
    }else {
        for(int i = 0; i < n; i++) {
            if(a[i] != -1 and dis[i] != a[i]) {
                cout << "-1\n";
                return;
            }
        }
        cout << res << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
