#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    i64 d;
    cin >> n >> k >> d;
    vector<i64> a(n), b;
    for(auto &x: a) cin >> x;
    b = a;
    sort(all(b));
    b.erase(unique(all(b)), b.end());

    vector<int> id(n);
    for(int i = 0; i < n; i++) {
        id[i] = lower_bound(all(b), a[i]) - b.begin();
    }

    auto calc = [&](int lim) -> i64 {
        if(lim < 0) return 0;
        vector<int> cnt((int)b.size(), 0);
        deque<int> mn, mx;
        i64 res = 0;
        int l = 0, num = 0;
        for(int r = 0; r < n; r++){
            if(++cnt[id[r]] == 1) num++;
            while(!mn.empty() and a[mn.back()] >= a[r]) {
                mn.pop_back();
            }
            mn.push_back(r);
            while(!mx.empty() and a[mx.back()] <= a[r]) {
                mx.pop_back();
            }
            mx.push_back(r);

            while(l <= r and (num > lim or a[mx.front()] - a[mn.front()] > d)){
                if(--cnt[id[l]] == 0) num--;
                if(mn.front() == l) mn.pop_front();
                if(mx.front() == l) mx.pop_front();
                l++;
            }
            res += r - l + 1;
        }
        return res;
    };

    cout << calc(k) - calc(k - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}