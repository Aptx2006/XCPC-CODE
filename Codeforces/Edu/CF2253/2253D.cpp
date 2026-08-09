#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct nod{
    int val, type;
    const operator < (const nod& rhs) const{
        return val < rhs.val;
    };
};

void solve() {
    i64 x, y;
    cin >> x >> y;

    i64 k = sqrtl(2.0 * (x + y)) - 2;
    while((k + 1) * (k + 2) / 2 <= x + y) {
        k++;
    }
  
    i64 sum = k * (k + 1) / 2;
    i64 low = max(0LL, sum - y), high = min(sum, x);
    i64 ans = -1, mn = 2e18; 

    vector<i64> a = {low, high};
    for(i64 i = (sum + x - y) / 2 - 10; i <= (sum + x - y) / 2 + 10; i++) {
        a.push_back(max(low, min(high, i)));
    }
  
    for(auto p : a) {
        i64 q = sum - p;
        i64 cur = (x - p) * (x - p) + (y - q) * (y - q);
        if(cur < mn) {
            mn = cur;
            ans = p;
        }
    }
  
    string s(k, 'Y');
    for(int i = 1; i <= k; i++) {
        i64 val = k - i + 1;
        if(ans >= val) {
            ans -= val;
            s[i - 1] = 'X';
        }
    }
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
