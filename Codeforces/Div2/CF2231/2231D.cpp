#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

i64 T, n, m, k, cnt;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    vector<i64> a(n), c(n), ans(n);
    for(auto &x: a) cin >> x;
    for(auto &x: c) cin >> x;
    for(int i = 1; i < n; i++) {
        if(c[i] < c[i - 1]) {
            cout << "No\n";
            return;
        }
    }

    i64 last = 0, end = 0;
    auto isok = [&](int r, bool need, i64 tag){
        i64 cur = c[last];
        i64 i = last + 1;
        while(i <= r) {
            if(s[i] == '1') {
                cur += a[i];
                if(cur > c[last]) return false;
                ans[i] = a[i];
                i++;
                continue;
            }
            i64 j = i + 1;
            i64 sum = 0, mx = 0;
            while(j <= r and s[j] == '1') {
                sum += a[j];
                mx = max(mx, sum);
                j++;
            }
            i64 x;
            if(need and j > r) {
                x = tag - sum;
            } else {
                x = c[last] - mx;
            }
            if(x > c[last]) return false;
            if(x + mx > c[last]) return false;
            ans[i] = x - cur;
            cur = x;
            for(int k = i + 1; k < j; k++) {
                ans[k] = a[k];
                cur += a[k];
            }
            i = j;
        }
        end = cur;
        if(need and cur != tag) return false;
        return true;
    };

    if(s[0] == '1' and a[0] != c[0]) {
        cout << "No\n";
        return;
    }

    ans[0] = c[0];

    for(int i = 1; i < n; i++) {
        if(c[i] == c[i - 1]) continue;
        bool need = 0;
        i64 tag = 0;
        if(s[i] == '1') {
            need = 1;
            tag = c[i] - a[i];
        }
        if(!isok(i - 1, need, tag)) {
            cout << "No\n";
            return;
        }
        if(s[i] == '1') {
            ans[i] = a[i];
        } else {
            ans[i] = c[i] - end;
        }
        last = i;
    }
    if(!isok(n - 1, false, 0)) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
