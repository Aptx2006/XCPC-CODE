#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<char> op(n + 1);
    vector<int> l(n), r(n), del(n + 1);
    unordered_map<int, int> id;
    id.reserve(2 * n);

    int tot = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> op[i] >> x;
        if (op[i] == '+') {
            l[tot] = r[tot] = i;
            id[x] = tot++;
        } else if (op[i] == 'T') {
            r[id[x]] = i;
        }
    }

    vector<int> stk;
    stk.reserve(tot);
    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (p < tot && l[p] == i) stk.push_back(p++);
        while (!stk.empty() && r[stk.back()] <= i) {
            stk.pop_back();
            del[i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (op[i] == '+' ? '+' : '?');
        while (del[i]--) cout << '-';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
