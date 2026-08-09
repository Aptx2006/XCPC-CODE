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
    int x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(x), b(y);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    priority_queue<nod> pq;
    int i = 0, j = 0;
    while(i < x and j < y) {
        if(a[i] < b[j]) {
            pq.push({a[i++], 0});
        }else if(a[i] > b[j]) {
            pq.push({b[j++], 1});
        }else {
            pq.push({a[i++], 2});
            j++;
        }
    }
    for(; i < x; i++) pq.push({a[i], 0});
    for(; j < y; j++) pq.push({b[j], 1});

    i64 sum = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    while(!pq.empty()) {
        if(cnt1 + cnt2 + cnt3 >= n + m - 1) break;
        auto [v, ty] = pq.top();
        pq.pop();
        if(ty == 0 and cnt1 < n) {
            cnt1++;
            sum += v;
        }else if(ty == 1 and cnt2 < m) {
            cnt2++;
            sum += v;
        }else if(ty == 2){
            cnt3++;
            sum += v;
        }
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
