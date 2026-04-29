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
    int mxa  = *max_element(all(a));
    vector<int> mp(mxa + 1, 0);

    auto isok = [&](int x) {
        if(x == 0) return true;
        vector<int> cnt = mp;
        vector<int> need;
        for(int v = 0; v < x; v++) {
            if(v <= mxa and cnt[v] > 0) cnt[v]--;
            else need.push_back(v);
        }
        if(need.empty()) return true;

        int B = max(1, (int)sqrt(mxa + 1));
        int nb = (mxa + B) / B + 1;
        vector<int> block(nb, 0);
        for(int i = 0; i <= mxa; i++) block[i / B] += cnt[i];

        for(int v : need) {
            int sz = 2 * v + 1;
            if(sz > mxa) return false;
            int id = sz / B;
            bool f = 0;
            for(int i = id; i < nb; i++) {
                if(block[i] == 0) continue;
                int L = i * B;
                int R = min(mxa, L + B - 1);
                int st = max(L, sz);
                for(int j = st; j <= R; j++) {
                    if(cnt[j] > 0) {
                        cnt[j]--;
                        block[i]--;
                        f = 1;
                        break;
                    }
                }
                if(f) break;
            }
            if(!f) return false;
        }
        return true;
    };
    vector<int> res;
    for(int i = 0; i < n; i++){
        int v = a[i];
        if(v > mxa){
            mp.resize(v + 1);
            mxa = v;
        }
        mp[v]++;
        int l = 0, r = i + 1, ans = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(isok(mid)) {
                ans = mid;
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        res.push_back(ans);
    }
    n = res.size();
    for(int i = 0; i < n; i++) cout << res[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
