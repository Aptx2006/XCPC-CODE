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
    int pos_f1 = -1, pos_l1 = -1, pos_f2 = -1, pos_l2 = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            if (pos_f1 == -1) pos_f1 = i;
            pos_l1 = i;
        }
        if(a[i] == -1) {
            if (pos_f2 == -1) pos_f2 = i;
            pos_l2 = i;
        }
    }

    for(auto &x : a) {
        if (x == -1) x = 0;
    }

    if(pos_f1 == -1) {
        if(pos_f2 != -1) {
            a[pos_f2] = 1;
            a[pos_l2] = 1;
        }
    }else {
        if(pos_f2 != -1 and pos_f2 < pos_f1) {
            a[pos_f2] = 1;
        }
        if(pos_l2 != -1 and pos_l2 > pos_l1) {
            a[pos_l2] = 1;
        }
    }
    for(auto &x: a) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}