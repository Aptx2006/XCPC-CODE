#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

const i64 INF = (1LL << 60), MOD = 998244353;
i64 T, n, m, k, ans, cnt;

void print128(i128 x){
    if(x<0){
        putchar('-');
        x = -x;
    }
    if(x > 9) print128(x/10);
    putchar(x % 10 + '0');
}

void solve() {
    cin >> n;
    priority_queue<i128> pq;
    while(n--) {
        cin >> k;
        pq.push(k);
    }
    i128 ans = 0;
    while((i32)pq.size() > 1) {
        i128 cur = pq.top();
        ans += cur;
        pq.pop();
        cur += pq.top();
        pq.pop();
        pq.push(cur);
    }
    print128(ans);
    putchar('\n');
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
