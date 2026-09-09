#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct nod{
    int sum = 0, mn = 0;
    nod(int sum = 0, int mn = 0): sum(sum), mn(mn){};
};

nod merge(const nod &a, const nod &b) {
    int nsum = a.sum + b.sum;
    int nmn = min(a.mn, a.sum + b.mn);
    return nod(nsum, nmn);
}

void solve() {
    cin >> n;
    string s;
    cin >> s;
    s = " " + s; 
    const int B = sqrt(n) + 1;
    const int sz = (n + B - 1) / B;
    vector<nod> a(sz);

    auto fun = [&](int i) {
        return s[i] == 'A' ? 1 : -1;
    };

    auto work = [&](int id) {
        int l = id * B + 1;
        int r = min(n, (id + 1) * B);
        nod cur;
        for(int j = l; j <= r; j++) {
            cur = merge(cur, nod(fun(j), min(0, fun(j))));
        }
        a[id] = cur;
    };

    for(int i = 0; i < sz; i++) work(i);

    auto ask = [&](int l, int r) {
        nod res;
        while(l <= r) {
            int id = (l - 1) / B;
            int L = id * B + 1;
            int R = min(n, (id + 1) * B);
            if(l == L and R <= r) {
                res = merge(res, a[id]);
                l = R + 1;
            } else {
                nod cur(fun(l), min(0, fun(l)));
                res = merge(res, cur);
                l++;
            }
        }
        return res;
    };

    int q;
    cin >> q;
    while(q--) {
        int op, i, l, r;
        char c;
        cin >> op;
        if(op == 1) {
            cin >> i >> c;
            s[i] = c;
            work((i - 1) / B);
        }else {
            cin >> l >> r;
            nod res = ask(l, r);
            cout << (res.mn >= 0 ? "Yes\n" : "No\n");
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}