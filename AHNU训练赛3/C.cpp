#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct E{
    int a, b, id;
};

void solve() {
    cin >> n;
    vector<E> e(n);
    for(int i = 0; i < n; i++) {
        cin >> e[i].a >> e[i].b;
        e[i].id = i;
    }
    sort(all(e), [&](auto o1, auto o2){
        if(o1.a != o2.a) return o1.a < o2.a;
        return o1.b > o2.b;
    });
    vector<int> out(n), tmp(n);
    auto isok = [&](int mid){
        if(mid == 0) return true;
        tmp.clear();
        cnt = 0;
        for(int i = 0; i < (int)e.size() and cnt < mid; ) {
            int j = i;
            while(j < (int)e.size() and e[j].a == e[i].a) j++;
            int res = min(j - i, mid - cnt);
            int sz = 0;
            for(int t = res; t >= 1; t--) {
                int need = max(0, mid - cnt - t);
                if(need <= e[i + t - 1].b) {
                    sz = t;
                    break;
                }
            }
            for(int k = 0; k < sz; k++) tmp.push_back(e[i + k].id);
            cnt += sz;
            i = j;
        }
        return cnt == mid;
    };
    int l = 0, r = 1e9;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(isok(mid)) {
            l = mid + 1;
            ans = mid;
            out = tmp;
        }else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    for(auto &x: out) cout << x + 1 << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
