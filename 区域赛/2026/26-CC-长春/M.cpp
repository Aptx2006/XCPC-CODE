#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define all(A) A.begin(), A.end()
#define dbg(A) cerr << #A << ':' << A << endl;
int n, m, k;

void solve(){
    cin >> n >> m;
    int sz = m + 5;
    vector<i64> cnt(sz), a(n), b(n + 5), c(n + 5);
    for(auto &x: a) cin >> x;

    for(int i = 1; i < sz; i++) {
        for(int j = i; j < sz; j += i) {
            cnt[j]++;
        }
    }

    //for(int i = 1; i <= m; i++) cout << i << ' ' << cnt[i] << endl; 
    i64 ans = 0;
    cnt[0] = m;
    for(int i = 0; i < n; i++) {
        i64 cur = 0;
        //dbg(cur)
        for(int l = i - 1, r = i + 1; r < n and l >= 0; l--, r++) {
            cur = __gcd(cur, llabs(a[l] - a[r]));
            ans += cnt[cur] - 1;
            //dbg(cur)
            //dbg(l) dbg(r)
        }

        cur = 0;
        for(int l = i, r = i + 1; r < n and l >= 0; l--, r++) {
            cur = __gcd(cur, llabs(a[l] - a[r]));
            ans += cnt[cur] - 1;
            //dbg(l) dbg(r)
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1, r;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
