#include<bits/stdc++.h>
using namespace std;

using i32 = int;
// using i64 = long long;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> k;
    vector<i64> a(n);
    i64 sum = 0, mx = 0;
    for(auto &x: a) {
        cin >> x;
        sum += x, mx = max(mx, x);
    }
    sum += k;
    vector<i64> fact;
    for(i64 i = 1; i * i <= sum; i++) {
        if(sum % i == 0) {
            fact.emplace_back(i);
            fact.emplace_back(sum / i);
        }
    }
    sort(all(fact), greater<i64>());
    vector<i64> buc(mx + 5), pre(mx + 5), pre_sz(mx + 5);
    for(const auto &x: a) {
        buc[x]++;
    }
    for(i64 i = 1; i <= mx; i++) {
        pre[i] = pre[i - 1] + i * buc[i];
        pre_sz[i] = pre_sz[i - 1] + buc[i];
    }
    i128 cnt = 0;
    for(const auto &f: fact) {
        if(f >= mx) {
            cnt = ((i128)f * n + k - sum);
        }else {
            cnt = 0;
            // for(const auto &x: a) {
            //     i64 t = (f - x % f);
            //     if(t != f)  cnt += t;
            // }
            i64 c = 1;
            for(i64 l = 1; l <= mx; l += f) {
                i64 r = min(mx, l + f - 1);
                i64 sz = pre_sz[r] - pre_sz[l - 1];
                cnt += (i128)f * sz * c - (pre[r] - pre[l - 1]);
                c++;
            }
        }
        if(k >= cnt and (k - cnt) % f == 0) {
            ans = f;
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
}
