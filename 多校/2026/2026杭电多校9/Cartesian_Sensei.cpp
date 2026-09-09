#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<int> a(n + 1), dist(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    stack<int> st;
    for(int i = 1; i <= n; i++) {
        while(!st.empty() and a[st.top()] > a[i]) {
            st.pop();
        }
        int pos = st.empty() ? 0 : st.top();
        dist[i] = i - pos;
        st.push(i);
    }
    vector<int> pi(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        int j = pi[i - 1];
        while(j > 0 and min(dist[j + 1], j + 1) != min(dist[i], j + 1)) {
            j = pi[j];
        }
        if(min(dist[j + 1], j + 1) == min(dist[i], j + 1)) {
            j++;
        }
        pi[i] = j;
    }
    for(int i = 1; i <= n; i++) {
        cout << pi[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
