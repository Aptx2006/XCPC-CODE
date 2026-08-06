#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned int;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

int fa[30];
int find(int x){return x == fa[x]? x: fa[x] = find(fa[x]);}

// 计算并返回 z 数组，其中 z[i] = |LCP(s[i:], s)|
vector<int> calc_z(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int box_l = 0, box_r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= box_r) {
            z[i] = min(z[i - box_l], box_r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            box_l = i;
            box_r = i + z[i];
            z[i]++;
        }
    }
    z[0] = n;
    return z;
}
/*
作者：灵茶山艾府
链接：https://leetcode.cn/discuss/post/SJFwQI/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

void solve() {
    string s;
    cin >> s;
    vector<int> z = calc_z(s);
    n = s.size();
    u32 req[30]{0};
    for(int i = 1; i < n; i++) {
        if(z[i] == n - i) {
            cout << 0 << '\n';
            return;
        }
        req[s[i + z[i]] - 'a'] |= (1 << (s[z[i]] - 'a'));
    }
    
    s = "";

    for(int i = 0; i < 30; i++) {
        fa[i] = i;
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(req[i] >> j & 1) fa[find(i)] = find(j);
        }
    }
    
    vector<int> pos[30];
    for(int i = 0; i < 26; i++) {
        pos[find(i)].push_back(i);
    }

    u32 comb[30][30]{0};
    for(int i = 0; i <= 26; i++) {
        comb[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    
    u32 ans = 1, sz = 26;
    for(int i = 0; i < 26; i++) {
        if(pos[i].empty()) continue;
        k = pos[i].size();
        
        ans *= comb[sz][k];
        sz -= k;
        if(k == 1) continue;
        
        int mask[30]{};
        for(int j = 0; j < k; j++) {
            for(int p = 0; p < k; p++) {
                if(req[pos[i][j]] >> pos[i][p] & 1) mask[j] |= (1 << p);
            }
        }
        
        int B = 1 << k;
        vector<u32> dp(B);
        dp[0] = 1;
        for(int st = 0; st < B; st++) {
            if(!dp[st]) continue;
            int cur = (B - 1) ^ st;
            while(cur) {
                int p = __builtin_ctz(cur);
                if((mask[p] & st) == mask[p]) dp[st | (1 << p)] += dp[st];
                cur &= cur - 1;
            }
        }
        ans *= dp[B - 1];
        if(!ans) {
            cout << 0 << '\n';
            return;
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
