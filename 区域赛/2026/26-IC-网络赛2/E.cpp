#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1;
i64 n, ans;

i64 get_pfac(i64 x, vector<pair<i64, i64>> &fac) {
    i64 phi = x;
    for (i64 i = 2; i <= x / i; i++) {
        if (x % i) continue;
        i64 pw = 1;
        phi = phi / i * (i - 1);
        while (x % i == 0) {
            x /= i;
            pw *= i;
        }
        fac.push_back({i, pw});
    }
    if (x > 1) {
        fac.push_back({x, x});
        phi = phi / x * (x - 1);
    }
    return phi;
}

vector<i64> get_fac(i64 x) {
    vector<i64> fac;
    for (i64 i = 1; i <= x / i; i++) {
        if (x % i) continue;
        fac.push_back(i);
        if (i != x / i) fac.push_back(x / i);
    }
    sort(all(fac));
    return fac;
}

i64 get_ans1(i64 t, i64 p, i64 pw) {
    return gcd(t, pw / p * (p - 1));
}

i64 get_ans2(i64 t, i64 pw) {
    return gcd(2LL, t) * gcd(t, pw / 4);
}

void solve() {
    cin >> n;
    vector<pair<i64, i64>> pfac;
    i64 phi = get_pfac(n, pfac);
    vector<i64> fac = get_fac(phi), a;
    for (auto t: fac) {
        i64 res = 1;
        for (auto [p, pw]: pfac) {
            if (p == 2 && pw > 4) res *= get_ans2(t, pw);
            else res *= get_ans1(t, p, pw);
        }
        a.push_back(res);
    }

    ans = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (fac[i] % fac[j] == 0) a[i] -= a[j];
        }
        ans += fac[i] * a[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
