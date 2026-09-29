#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

const int mod1 = 1E9 + 7, base1 = 127;
const int mod2 = 1E9 + 9, base2 = 131;
vector<int> val1, val2;

void init(int n) {
    val1.resize(n + 1);
    val2.resize(n + 1);
    val1[0] = val2[0] = 1;
    for (int i = 1; i <= n; i++) {
        val1[i] = 1LL * val1[i - 1] * base1 % mod1;
        val2[i] = 1LL * val2[i - 1] * base2 % mod2;
    }
}

struct String {
    vector<int> hash1;
    vector<int> hash2;
    string s;

    String(string s_) : s(s_), hash1{1}, hash2{1} {
        for (auto it: s) {
            hash1.push_back((1LL * hash1.back() * base1 + it) % mod1);
            hash2.push_back((1LL * hash2.back() * base2 + it) % mod2);
        }
    }
    pair<int, int> get() {
        return {hash1.back(), hash2.back()};
    }
    pair<int, int> substring(int l, int r) {
        if (l > r) swap(l, r);
        int len = r - l + 1;
        int ans1 = (hash1[r + 1] - 1LL * hash1[l] * val1[len] % mod1 + mod1) % mod1;
        int ans2 = (hash2[r + 1] - 1LL * hash2[l] * val2[len] % mod2 + mod2) % mod2;
        return {ans1, ans2};
    }
    pair<int, int> modify(int idx, char x) {
        int n = s.size() - 1;
        int ans1 = (hash1.back() + 1LL * val1[n - idx] * (x - s[idx]) % mod1 + mod1) % mod1;
        int ans2 = (hash2.back() + 1LL * val2[n - idx] * (x - s[idx]) % mod2 + mod2) % mod2;
        return {ans1, ans2};
    }
};

void solve() {
    cin >> n;
    init(500000);
    vector<int> f(n + 1);
    unordered_map<u64, int> mp;
    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        String str(s);
        sum += i;
        auto getHash = [&](int len) -> u64{
            auto [h1, h2] = str.substring(0, len - 1);
            return u64(u64(h1) << 32 | h2);
        };
        for (int j = 1; j <= (int)s.size(); j++) {
            int c = ++mp[getHash(j)];
            if (f[c] < j) {
                sum -= f[c] ^ c;
                f[c] = j;
                sum += f[c] ^ c;
            }
        }
        cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
