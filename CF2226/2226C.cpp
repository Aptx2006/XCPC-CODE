#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int l = 0, r = n;
    ans = 0;
    sort(all(a));
    
    auto isok = [&](int x) {
        vector<int> tag(x, 1), b;
        for(auto &v: a) {
            if(v >= x) b.push_back(v);
            else if(tag[v]) tag[v] = 0;
            else b.push_back(v);
        }
        int pb = 0;
        for(int i = 0; i < x; i++) {
            while(pb < (int)b.size() and tag[i]) {
                if(b[pb++] - 1 >= 2 * i) tag[i] = 0;
            }
            if(!tag[i]) continue;
            return false;
        }
        return true;
    };

    while(l <= r) {
        int mid = (l + r) >> 1;
        if(isok(mid)) {
            ans = mid;
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
