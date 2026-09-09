#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

<<<<<<< HEAD
int T = 1, n, m, k, cnt;
i64 ans;

const u64 BASE = 131;

struct Hash {
    vector<u64> h, pw;

    Hash(string s) {
        int n = s.size();
        h.resize(n + 1);
        pw.resize(n + 1);
        pw[0] = 1;

        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] * BASE + s[i];
            pw[i + 1] = pw[i] * BASE;
        }
    }

    // 返回 s[l...r-1] 的哈希值。
    u64 get(int l, int r) {
        return h[r] - h[l] * pw[r - l];
    }
};

void solve() {
    string s;
    cin >> s;
    n = s.size();

    string rev = s;
    reverse(all(rev));

    Hash hs(s), hr(rev);

    // 从 l 向左、从 r 向右，最多比较 limit 对字符。
    auto lcp = [&](int l, int r, int limit) {
        int low = 0, high = limit;

        while (low < high) {
            int mid = (low + high + 1) / 2;

            // s[l], s[l-1], ... 在 rev 中是正向连续子串。
            if (hr.get(n - 1 - l, n - 1 - l + mid)
                == hs.get(r, r + mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    };

    // 统计以 l、r 为最内层字符的好子串数量。
    auto calc = [&](int l, int r) {
        int limit = min(l + 1, n - r);
        if (limit <= 0) return 0;

        // 第一对不同字符之前，有 x 对相同。
        int x = lcp(l, r, limit);

        // 所有字符都相同。
        if (x == limit) return limit;

        // 跳过第一对不同字符。
        int remain = limit - x - 1;

        // 继续寻找第二对不同字符。
        int y = lcp(l - x - 1, r + x + 1, remain);

        return x + 1 + y;
    };

    ans = 0;

    for (int i = 0; i < n; i++) {
        // 奇数长度，中心是 s[i]。
        ans += calc(i, i);

        // 偶数长度，中心在 s[i] 和 s[i+1] 之间。
        ans += calc(i, i + 1);
    }

    cout << ans << '\n';
=======
int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i64> a(n, 1), b(n);
    for(auto &x: b) cin >> x;
    map<i64, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        mp[b[i]].push_back(i);
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    i64 lastans = 0;
    if(b[0] != 0) {
        cout << "-1\n";
        return;
    }
    for(int i = 1; i < (int)b.size(); i++) {
        int sz = mp[b[i - 1]].size();
        i64 cur = b[i] - b[i - 1];
        i64 ans = cur / sz;
        if(cur % sz != 0 or ans <= lastans) {
            cout << "-1\n";
            return;
        }
        for(auto &j: mp[b[i - 1]]) {
            a[j] = ans;
        }
        lastans = ans;
    }
    for(auto &j: mp[b.back()]) a[j] = lastans + 1;
    for(auto &x: a) cout << x << ' ';
    cout << '\n';
>>>>>>> d5366e4a59a6146306aea65080b93488b1ce3605
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}