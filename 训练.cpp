#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;

int n;
i64 ans;
vector<int> a, tmp;

void mergesort(int l, int r) {
    if(r - l <= 1) return;
    int m =(l + r) >> 1;
    mergesort(l, m);
    mergesort(m, r);

    int i = l, j = m, k = l;
    while(i < m and j < r) {
        if(a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            ans += m - i;
            tmp[k++] = a[j++];
        }
    }
    while(i < m) tmp[k++] = a[i++];
    while(j < r) tmp[k++] = a[j++];
    for(int p = l; p < r; ++p) a[p] = tmp[p];
};

void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) cin >> x;
    tmp.resize(n);
    mergesort(0, n);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
