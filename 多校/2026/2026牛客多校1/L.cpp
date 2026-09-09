#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

using ull = unsigned long long;
ull base = 131;
ull mod1 = 212370440130137957, mod2 = 1e9 + 7;

ull get_hash1(std::string s) {
  int len = s.size();
  ull ans = 0;
  for (int i = 0; i < len; i++) ans = ((i128)ans * base + (ull)s[i]) % mod1;
  return ans;
}

ull get_hash2(std::string s) {
  int len = s.size();
  ull ans = 0;
  for (int i = 0; i < len; i++) ans = (ans * base + (ull)s[i]) % mod2;
  return ans;
}

bool cmp(const std::string s, const std::string t) {
  bool f1 = get_hash1(s) != get_hash1(t);
  bool f2 = get_hash2(s) != get_hash2(t);
  return f1 || f2;
}

const int MOD = 998244353;

void solve() {
    int q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<i64> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    vector<i64> min_pref(n + 1, 0);
    min_pref[0] = pref[0];
    for (int i = 1; i <= n; i++) {
        min_pref[i] = min(min_pref[i - 1], pref[i]);
    }

    vector<i64> max_pref(n + 2, -4e18);
    max_pref[n] = pref[n];
    for (int i = n - 1; i >= 1; i--) {
        max_pref[i] = max(max_pref[i + 1], pref[i]);
    }

    vector<i64> sum_pref(n + 1, 0);
    sum_pref[0] = (pref[0] % MOD + MOD) % MOD;
    for (int i = 1; i <= n; i++) {
        sum_pref[i] = (sum_pref[i - 1] + (pref[i] % MOD + MOD) % MOD) % MOD;
    }

    vector<i64> suff_pref(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        suff_pref[i] = (suff_pref[i + 1] + (pref[i] % MOD + MOD) % MOD) % MOD;
    }

    vector<ull> H1(n + 1, 0), P1(n + 1, 1);
    vector<ull> H2(n + 1, 0), P2(n + 1, 1);
    for (int i = 0; i < n; i++) {
        H1[i + 1] = ((i128)H1[i] * base + s[i]) % mod1;
        P1[i + 1] = ((i128)P1[i] * base) % mod1;
        H2[i + 1] = (H2[i] * base + s[i]) % mod2;
        P2[i + 1] = (P2[i] * base) % mod2;
    }

    auto get_sub_hash = [&](int l, int r) -> pair<ull, ull> {
        int len = r - l + 1;
        ull h1 = (H1[r + 1] + mod1 - (ull)(((i128)H1[l] * P1[len]) % mod1)) % mod1;
        ull h2 = (H2[r + 1] + mod2 - (H2[l] * P2[len]) % mod2) % mod2;
        return {h1, h2};
    };

    vector<string> qs(q);
    unordered_map<string, int> str_to_id;
    vector<string> aa;
    vector<int> q_to_uid(q);

    for (int i = 0; i < q; i++) {
        cin >> qs[i];
        if (!str_to_id.count(qs[i])) {
            str_to_id[qs[i]] = aa.size();
            aa.push_back(qs[i]);
        }
        q_to_uid[i] = str_to_id[qs[i]];
    }

    int num_u = aa.size();
    vector<vector<int>> by_len(n + 1);
    for (int uid = 0; uid < num_u; uid++) {
        if ((int)aa[uid].size() <= n) {
            by_len[aa[uid].size()].push_back(uid);
        }
    }

    vector<i64> ans_max(num_u, -4e18);
    vector<i64> ans_sum(num_u, 0);

    for (int len = 1; len <= n; len++) {
        if (by_len[len].empty()) continue;

        vector<pair<pair<ull, ull>, int>> targets;
        targets.reserve(by_len[len].size());
        for (int uid : by_len[len]) {
            ull h1 = get_hash1(aa[uid]);
            ull h2 = get_hash2(aa[uid]);
            targets.push_back({{h1, h2}, uid});
        }
        sort(targets.begin(), targets.end());

        vector<vector<int>> match_pos(by_len[len].size());
        auto get_target_idx =  [&](pair<ull, ull> h) -> int {
            auto it = lower_bound(targets.begin(), targets.end(), make_pair(h, -1));
            if (it != targets.end() && it->first == h) {
                return it - targets.begin();
            }
            return -1;
        };

        for (int i = 0; i <= n - len; i++) {
            pair<ull, ull> cur_h = get_sub_hash(i, i + len - 1);
            int idx = get_target_idx(cur_h);
            if (idx != -1) {
                match_pos[idx].push_back(i + 1); 
            }
        }

        for (size_t idx = 0; idx < targets.size(); idx++) {
            int uid = targets[idx].second;
            const auto& pos = match_pos[idx];
            if (pos.empty()) continue;

            i64 cur_max = -4e18;
            i64 cur_sum = 0;

            int prev_p = 0;
            for (int p : pos) {
                int end_pos = p + len - 1;

                cur_max = max(cur_max, max_pref[end_pos] - min_pref[p - 1]);

                i64 len_left = p - prev_p;
                i64 len_right = n - end_pos + 1;
                i64 s_r = suff_pref[end_pos];
                i64 s_l = (sum_pref[p - 1] - (prev_p > 0 ? sum_pref[prev_p - 1] : 0) + MOD) % MOD;

                i64 term = (len_left % MOD * s_r - len_right % MOD * s_l) % MOD;
                cur_sum = (cur_sum + term + MOD) % MOD;

                prev_p = p;
            }

            ans_max[uid] = cur_max;
            ans_sum[uid] = cur_sum;
        }
    }

    for (int i = 0; i < q; i++) {
        int uid = q_to_uid[i];
        cout << ans_max[uid] << " " << ans_sum[uid] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}