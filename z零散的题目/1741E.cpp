#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m, k, T;

void solve() {
    cin >> n;
    unordered_set<int> dp;
    dp.insert(0);
    for(int bi, i = 1; i <= n; i++) {
        cin >> bi;
        if(dp.count(i - bi - 1)) dp.insert(i);
        if(dp.count(i - 1)) dp.insert(i + bi);
    }
    cout << (dp.count(n) ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--;solve());
}
