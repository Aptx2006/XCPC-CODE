#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()

struct nod {
    int x, y;
};

void solve() {
    int n;
    cin >> n;
    vector<nod> p(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        a[i] = p[i].y;
    }

    sort(all(p), [](auto &a, auto &b) {  return a.x < b.x;});

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    vector<int> premn(n), premx(n);
    vector<int> sufmn(n), sufmx(n);

    premn[0] = p[0].y;
    premx[0] = p[0].y;
    for (int i = 1; i < n; i++) {
        premn[i] = min(premn[i - 1], p[i].y);
        premx[i] = max(premx[i - 1], p[i].y);
    }

    sufmn[n - 1] = p[n - 1].y;
    sufmx[n - 1] = p[n - 1].y;
    for (int i = n - 2; i >= 0; i--) {
        sufmn[i] = min(sufmn[i + 1], p[i].y);
        sufmx[i] = max(sufmx[i + 1], p[i].y);
    }

    i64 ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (p[i].x != p[i + 1].x) {
            int L = max(premn[i], sufmn[i + 1]);
            int R = min(premx[i], sufmx[i + 1]) - 1;

            if (L <= R) {
                ans += upper_bound(all(a), R) - lower_bound(all(a), L);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T--; solve());
    return 0;
}
