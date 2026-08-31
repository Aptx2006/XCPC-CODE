#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
const int N = 5e5 + 5;
u64 xjs[N][3];
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    cin >> n;
    vector<i64> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<u64> pre_hash(n + 1, 0);         
    vector<int> pre_cnt(n + 1, 0), cur_cnt(n + 1, 0);
    map<u64, int> mp;
    i64 ans = 0;
    int L = 1;
    mp[0] = 1; 
    for(int R = 1; R <= n; R++) {
        int x = a[R];
        cur_cnt[x]++;
        while(cur_cnt[x] > 3) {
            mp[pre_hash[L - 1]]--;      
            cur_cnt[a[L]]--;   
            L++;
        }
        auto &cnt = pre_cnt[x];
        pre_hash[R] = pre_hash[R - 1] ^ xjs[x][cnt % 3] ^ xjs[x][++cnt % 3];
        ans += mp[pre_hash[R]];
        mp[pre_hash[R]]++;
    }

    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < N; i++) {
        xjs[i][1] = rnd();
        xjs[i][2] = rnd();
        xjs[i][0] = 0;
    }
    for(; T--; solve());
    return 0;
}
