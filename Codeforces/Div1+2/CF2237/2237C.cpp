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
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    vector<i64> st;

    for(int x: a) {
        i64 cur = x;
        while(!st.empty() and st.back() > cur) {
            cur += st.back();
            st.pop_back();
        }
        st.push_back(cur);
    }
    
    cout << *max_element(all(st)) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}