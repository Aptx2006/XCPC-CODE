#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n, m;

void solve() {
    cin >> n >> m;
    unordered_set<int> st;
    while(n--) {
        int x; 
        cin >> x;
        st.insert(x);
    }
    while(m--) {
        int x; 
        cin >> x;
        if(st.count(x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
