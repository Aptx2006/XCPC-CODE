#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
ull base = 131;
ull mod1 = 212370440130137957;

vector<ull> pre_s, pre_t, pow_b;

void init(const string &s, const string &t) {
    int n = s.size(), m = t.size();
    int max_len = max(n, m);
    pow_b.resize(max_len + 1, 1);
    for (int i = 0; i < max_len; i++) {
        pow_b[i + 1] = ((unsigned __int128)pow_b[i] * base) % mod1;
    }
    
    pre_s.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre_s[i + 1] = ((unsigned __int128)pre_s[i] * base + s[i]) % mod1;
    }
    
    pre_t.resize(m + 1, 0);
    for (int i = 0; i < m; i++) {
        pre_t[i + 1] = ((unsigned __int128)pre_t[i] * base + t[i]) % mod1;
    }
}

ull get_sub_s(int l, int r) {
    return (pre_s[r] - (unsigned __int128)pre_s[l] * pow_b[r - l] % mod1 + mod1) % mod1;
}

ull get_sub_t(int l, int r) {
    return (pre_t[r] - (unsigned __int128)pre_t[l] * pow_b[r - l] % mod1 + mod1) % mod1;
}

string s, t;
int n, m;

bool check(int L) {
    if (L > m) return true;
    unordered_set<ull> st;
    st.reserve(m - L + 2); 
    for (int i = 0; i + L <= m; i++) {
        st.insert(get_sub_t(i, i + L));
    }
    for (int i = 0; i + L <= n; i++) {
        if (!st.count(get_sub_s(i, i + L))) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> s >> t;
    n = s.size(), m = t.size();
    init(s, t);
    
    int l = 1, r = n, ans = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
