#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        i64 n;
        cin >> n;
        vector<i64> a(n);
        for (auto& x : a) cin >> x;
        vector<i64> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] ^ a[i - 1];
        unordered_map<i64, i64> mp1, mp2;
        for (int i = 0; i <= n; i++)
            if (i & 1)
                mp2[pre[i]]++;
            else
                mp1[pre[i]]++;

        i64 cnt = 0;
        for (auto& [x, y] : mp1) cnt += y * (y - 1) / 2;

        for (auto& [x, y] : mp2) cnt += y * (y - 1) / 2;

        i64 sum = n * (n + 1) / 2;
        i64 id1 = (n + 2) / 2;
        i64 id2 = (n + 1) / 2;
        i64 len1 = id1 * id2;
        i64 len2 = sum - len1;

        cout << len2 - cnt << " " << sum - len2 + cnt << "\n";
    }

    return 0;
}