#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<int> a(n), dif(n);
    for(auto &x: a) cin >> x;
    for(int i = 0; i < n - 1; i++) dif[i] = a[i] - a[i + 1];
    int mx = *max_element(all(dif));

    if(mx == 0) {
        cout << "YES\n";
        return;
    }

    int last = -1;
    bool ok = 1;
    for(int i = 0; i < n - 1; i++) {
        if(dif[i] > 0) {
            if(last != -1) {
                bool f = 0;
                for(int j = last + 1; j < i; j++) {
                    if(a[j + 1] - a[j] >= mx) {
                        f = 1;
                        break;
                    }
                }
                if(!f) {
                    ok = 0;
                    break;
                }
            }
            last = i;
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
