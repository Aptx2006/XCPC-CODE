#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt, x;

void solve() {
    cin >> n >> x;
    int b = 0;
    for(int i = 0; i <= 30; i++) {
        if((x >> i) & 1) continue;
        b = i; 
        break;
    }
    int tag = 1 << b;
    //dbg(b) dbg(tag)
    if(n > tag) {
        for(int i = 0; i < tag; i++) cout << i << ' ';
        for(int i = 0; i < (n - tag - 1); i++) cout << "0 ";
        cout << x << '\n';
    }else {
        int cur = 0;
        for(int i = 0; i < (n - 1); i++) cout << i << ' ', cur |= i;
        cur |= (n - 1);
        if(cur == x) cout << n - 1 << '\n';
        else cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
