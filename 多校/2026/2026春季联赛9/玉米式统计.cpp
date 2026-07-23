#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<array<int, 3>> v(n);
    for(auto &[x, y, z]: v) cin >> x >> y >> z;
    i32 fz[3]{0}, fm[3]{0};
    for(auto &[x, y, z]: v) {
        if(x > 0) fz[0] += z, fm[0]++;
        if(y > 0) fz[1] += z, fm[1]++;
        if(x > 0 and y > 0) fz[2] += z, fm[2]++;
    }
    vector<double> res(3);
    for(int i = 0; i < 3; i++) {
        if(fm[i])
            res[i] = fz[i] * 100.0 / fm[i];
    }
    cout << fixed << setprecision(2) << *max_element(all(res)) << "%\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
