#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x, x = x & 1;
    cnt = 0;
    for(int i = 1; i < n; i++) {
        if(a[i - 1] == a[i]) cnt++;
    }
    if(n == 1) {
        cout << "1\n";
    }else if(cnt <= 1) {
        cout << "2\n";
    }else{
        cout << "0\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}