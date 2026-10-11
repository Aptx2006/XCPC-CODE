#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(A) cout << (#A) << ':' << A << endl;
#define all(A) (A).begin(), (A).end()

int n, m;

const int N = 1 << 21;
static const int mod1 = 1E9 + 7, base1 = 1111111121;
static const int mod2 = 1E9 + 9, base2 = 131;
using U = unsigned i64;
using V = U;
vector<U> val1;
vector<V> val2;
void init(int n = N) {
    val1.resize(n + 1), val2.resize(n + 2);
    val1[0] = 1, val2[0] = 1;
    for (int i = 1; i <= n; i++) {
        val1[i] = val1[i - 1] * base1;
        val2[i] = val2[i - 1] * base2;
    }
}
struct String {
    vector<U> hash1;
    vector<V> hash2;
    string s;
    
    String(string s_) : s(s_), hash1{1}, hash2{1} {
        for (auto it : s) {
            hash1.push_back(hash1.back() * base1 + it);
            hash2.push_back(hash2.back() * base2 + it);
        }
    }
    pair<U, V> get() { // 输出整串的哈希值
        return {hash1.back(), hash2.back()};
    }
    pair<U, V> substring(int l, int r) { // 输出子串的哈希值
        if (l > r) swap(l, r);
        U ans1 = hash1[r + 1] - hash1[l] * val1[r - l + 1];
        V ans2 = hash2[r + 1] - hash2[l] * val2[r - l + 1];
        return {ans1, ans2};
    }
    pair<U, V> modify(int idx, char x) { // 修改 idx 位为 x
        int n = s.size() - 1;
        U ans1 = hash1.back() + val1[n - idx] * (x - s[idx]);
        V ans2 = hash2.back() + val2[n - idx] * (x - s[idx]);
        return {ans1, ans2};
    }
};

vector<int> mxMatch(string s) {
    int len = s.length(), p = 0;
    vector<int> pi(len);
    for(int i = 1; i < len; i++) {
        while(p && s[i] != s[p]) {
            p = pi[p - 1];
        }
        if(s[i] == s[p]) {
            p++;
        }
        pi[i] = p;
    }

    return pi;
}

void solve() {
    i64 L, C, P;
    cin >> L >> C >> P;
    vector<string> s(L);
    int sum = 0;
    for(auto &x: s) {
        cin >> x;
        sum += x.size();
    }
    init(sum);
    vector<i64> powC(sum + 1);
    powC[0] = 1;
    for(int i = 1; i <= sum; i++) {
        powC[i] = powC[i - 1] * C % P;
    }

    auto getHash = [&](pair<U,V> x) {
        return x.first ^ (x.second << 1);
    };
    unordered_map<U, i64> mp;
    vector<String> hs;

    for(auto &x: s) {
        hs.push_back(x);
        int len = x.size();
        for(int i = 1; i <= len; i++) {
            auto h = hs.back().substring(len - i, len - 1);
            mp[getHash(h)]++;
        }
    }
    i64 ans = L * L % P;
    for(int id = 0; id < L; id++) {
        vector<int> pi = mxMatch(s[id]);
        int len = s[id].size();
        for(int i = 1; i <= len; i++) {
            auto h = hs[id].substring(0, i - 1);
            auto it = mp.find(getHash(h));
            if(it == mp.end()) {
                continue;
            }
            i64 cnt = it->second;
            ans += cnt * (powC[i] - powC[pi[i - 1]] + P) % P;
            ans %= P;
        }
    }

    cout << ans % P << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
