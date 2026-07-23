#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

const int INF = 2E9;
int T, n, m, k, ans, cnt;
int res[55][55];

void solve() {
    cin >> n >> k;
    i32 mn = n, mx = n * n - n + 1;
    if(k < mn or k > mx) {
        cout << "No\n";
    }else {
        cout << "Yes\n";
        i32 t = 1;
        res[1][1] = k;
        auto get = [&](){
            if(t == k) t++;
            return t++;
        };
        for(i32 i = 1; i <= n; i++) {
            for(i32 j = 1; j <= n; j++) {
                if(i == j) continue;
                res[i][j] = get();
            }
        }
        for(i32 i = 2; i <= n; i++) res[i][i] = get();
        for(i32 i = 1; i <= n; i++) {
            for(i32 j = 1; j <= n; j++) {
                cout << res[i][j] << " ";
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
