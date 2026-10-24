#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
#define all(A) A.begin(), A.end()
#define dbg(A) cerr << (#A) << ':' << (A) << endl;

int n;

void solve(){
    cin >> n;
    vector<int> a(n + 5);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    sort(all(a));
    int A = a[n + 4], B = a[n + 3];
    int ans = A | B | ((1 << max(0, __lg(A & B))) - 1);
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}