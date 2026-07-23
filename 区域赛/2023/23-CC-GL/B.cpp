#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    sort(all(a));
    sort(all(b));

    i64 sum_b = accumulate(all(b), 0LL);
    i64 sum_k = accumulate(a.begin() +(n - m), a.end(), 0LL);

    if(sum_b - sum_k > n - m) {
        cout << "-1\n";
        return;
    }

    // keep = 最大的m个, c = 其余
    multiset<int> keep, c;
    for(int i = 0; i < n - m; i++) c.insert(a[i]);
    for(int i = n - m; i < n; i++) keep.insert(a[i]);

    i64 cur_k = sum_k;
    vector<int> ans;
    int sz = n - m;

    // 保证keep = m
    auto work = [&]() {
        while((i64)keep.size() < m and !c.empty()) {
            auto it = prev(c.end());
            int v = *it;
            c.erase(it);
            keep.insert(v);
            cur_k += v;
        }
        while((i64)keep.size() > m) {
            auto it = keep.begin();
            int v = *it;
            keep.erase(it);
            cur_k -= v;
            c.insert(v);
        }
    };

    while(sz > 0 and sum_b - cur_k < sz) {
        int x = *c.begin();
        ans.push_back(x);
        c.erase(c.begin());

        int nx = x + 1;
        if(!keep.empty() and nx > *keep.begin()) {
            keep.insert(nx);
            cur_k += nx;
        } else {
            c.insert(nx);
        }

        if(!c.empty()) {
            c.erase(c.begin());
        } else {
            auto it = keep.begin();
            cur_k -= *it;
            keep.erase(it);
        }

        work();
        sz--;
    }

    vector<int> kk(all(keep));
    for(int i = 0; i < m; i++) {
        if(kk[i] > b[i]) {
            cout << "-1\n";
            return;
        }
    }

    if(sz > 0) {
        for(int i = m - 1; i >= 0 and sz > 0; i--) {
            while(kk[i] < b[i] and sz > 0) {
                ans.push_back(kk[i]);
                kk[i]++;
                if(!c.empty()) {
                    c.erase(c.begin());
                }
                sz--;
            }
        }
        if(kk != b) {
            cout << "-1\n";
            return;
        }
    }else {
        if(kk != b) {
            cout << "-1\n";
            return;
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T ; T--; solve());
    return 0;
}
